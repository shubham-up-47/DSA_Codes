#include <bits/stdc++.h>
using namespace std;

#define N 10
vector<string> grid(N);
vector<string> words;

bool isValidWord_H(string currWord, int i, int j)                         // checking validity of word for horizontal gap                   
{
	if(j-1>=0 && grid[i][j-1]!='+')
	return 0;
	else if(j+currWord.size()<N && grid[i][j+currWord.size()]!='+')
	return 0;
	
	for(int k=0; k<currWord.size(); k++)
	{  if(j+k<N && (grid[i][j+k]=='-' || grid[i][j+k]==currWord[k]))
	   continue;
	   else
	   return 0;  }
	
	return 1; 
}

bool isValidWord_V(string currWord, int i, int j)                         // checking validity of word for vertical gap 
{
	if(i-1>=0 && grid[i-1][j]!='+')
	return 0;
	else if(i+currWord.size()<N && grid[i+currWord.size()][j]!='+')
	return 0;
	                                                   
	for(int k=0; k<currWord.size(); k++)
	{  if(i+k<N && (grid[i+k][j]=='-' || grid[i+k][j]==currWord[k]))
	   continue;
	   else
	   return 0;  }
	
	return 1; 
}

void insertWord_H(string currWord, int i, int j, vector<bool> &changedI)  // inserting valid word in horizontal gap 
{ 
	for(int k=0; k<currWord.size(); k++)
	{  
	   if(grid[i][j+k]=='-')
	   {  grid[i][j+k]=currWord[k];
	      changedI[k] = 1;  }  
	} 
}

void insertWord_V(string currWord, int i, int j, vector<bool> &changedI)  // inserting valid word in vertical gap 
{ 
	for(int k=0; k<currWord.size(); k++)
	{  
	   if(grid[i+k][j]=='-')
	   {  grid[i+k][j]=currWord[k];
	      changedI[k] = 1;  }  
	} 
}

void removeWord_H(int i, int j, vector<bool> &changedI)                   // removing horizontal word after backtracking, to consider other cases     
{ 
	for(int k=0; k<changedI.size(); k++)
	{  
	   if(changedI[k]==1)
	   {  grid[i][j+k] = '-';
	      changedI[k] = 0;  }  
	} 
}
  
void removeWord_V(int i, int j, vector<bool> &changedI)                   // removing vertical word after backtracking, to consider other cases  
{ 
	for(int k=0; k<changedI.size(); k++)
	{  
	   if(changedI[k]==1)
	   {  grid[i+k][j] = '-';
	      changedI[k] = 0;  }  
	} 
}

void fillCrossword(int I_currWord)                   
{
	if(I_currWord==words.size())                                          // if crossword is solved, print crossword & return 
	{  cout<<"\n\nCrossword after solving:\n"; 
	   for(int i=0; i<N; i++)
	   cout<<grid[i]<<endl; 
	   return;  }
	
	string currWord = words[I_currWord];
	for(int i=0; i<N; i++)
	{  for(int j=0; j<N; j++)
       {  if(grid[i][j]=='-' || grid[i][j]==currWord[0])
          {
             vector<bool> changedI(currWord.size(), 0);
			 
			 if(isValidWord_H(currWord, i, j))
			 {  insertWord_H(currWord, i, j, changedI);
			    fillCrossword(I_currWord + 1);
			    removeWord_H(i, j, changedI);  }	
          	
			 if(isValidWord_V(currWord, i, j))
			 {  insertWord_V(currWord, i, j, changedI);
			    fillCrossword(I_currWord + 1);
			    removeWord_V(i, j, changedI);  }	 
		  }		
	   } 
	}
		
	return;	 
}


int main()
{
    for(int i=0; i<N; i++)                                                // storing (unsolved crossword of 10 X 10 grid) in (string vector array)        
    cin>>grid[i];
    
    string s, temp="";
    cin>>s;
    
    for(int i=0; i<s.size(); i++)                                         // storing (input word list) in a (string vector array)               
    {
       if(s[i]==';')
       {  words.push_back(temp);
	      temp = "";  }
	   else
	   temp += s[i]; 
    }
    words.push_back(temp);
    
    fillCrossword(0);                                                     // solving crossword by filling words at '-'            
}


/*

+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

*/


// (i,j) = (current row,current column), H = horizontal, V = vertical, I_currWord = (index no) of (current word)  
// currWord = string of (current word) which will be tried to fill during (current recursion call)        
// changedI[] = vector array storing (truth value of indexes) where ('-' char is replaced by currWord char)     





