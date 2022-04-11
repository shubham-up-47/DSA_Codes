#include <bits/stdc++.h>
using namespace std;

#define N 9
vector<vector<int>> grid(N, vector<int>(N));           // checking that we can safely place (grid[currR][currC] = num) or not                           

bool isSafe(int currR, int currC, int num)
{ 
	for(int i=0; i<N; i++)                             // is safe in row        
	{  if(grid[currR][i]==num)
	   return false;  }
	
	for(int i=0; i<N; i++)                             // is safe in column              
	{  if(grid[i][currC]==num)
	   return false;  }
	
	int rFactor = currR - currR%3;
	int cFactor = currC - currC%3;
	for(int i=0; i<3; i++)                             // is safe in corresponding 3 X 3 subgrid     
	{  for(int j=0; j<3; j++)
       {  if(grid[i+rFactor][j+cFactor]==num)
	      return false;  }  }
	      
	return true;                                       // we can safely place (grid[currR][currC] = num)     
}

bool findUnfilledLocation(int &currR, int &currC)
{
	for(int i=0; i<N; i++)
	{  for(int j=0; j<N; j++)
       {  
	      if(grid[i][j]==0)
	      {  currR = i;
	         currC = j;
		     return true;  } 
	   }
    }
	      
	return false;                                      // if no unfilled location found          
}

bool fillSudoku()
{
	int currR, currC;                                  // passing currR & currC by reference to store unfilled location in it     
	if(!findUnfilledLocation(currR,currC))
	return true;                                       // return true if no unfilled location left 
	
	for(int i=1; i<=N; i++)                            // i = current num which is filled at (currR, currC)           
	{  if(isSafe(currR, currC, i))                     // checking is it safe to fill (i) at (currR, currC)  
       {
	      grid[currR][currC] = i;                      // fill (i) if it is found safe                 
       
	      if(fillSudoku())                   
	      return true;
	      
	      grid[currR][currC] = 0;                      // if sudoku can't be solved using (i), unfill this num to consider other num  
	   }
    }
                                                        
	return false;                                      // return false & backtrack if (current sudoku) can't be filled further                   
}
                                                                                                                       
int main()
{
   for(int i=0; i<N; i++)                              // storing input partially filled sudoku 
   {  string s;
   	  cin>>s;
   	  for(int j=0; j<s.size(); j++)
   	  grid[i][j] = s[j]-'0';  }
   	  
   bool r = fillSudoku();                              // solving sudoku by filling empty (zero filled) boxes                 
   
   if(!r)
   cout<<"Sudoku can't be solved";
   else
   {  cout<<"\nSudoku after solving:\n";
 	  for(int i=0; i<N; i++)
	  {  for(int j=0; j<N; j++)
         cout<<grid[i][j]<<" ";   
		 cout<<endl;  }
   } 
}


/*

306508400
520000000
087000031
003010080
900863005
050090600
130000250
000000074
005206300
 
*/






