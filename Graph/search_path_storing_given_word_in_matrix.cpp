#include <bits/stdc++.h>
using namespace std;
 
// doFunctionCallAtNextEligibleBlock (in 1 out of 8 directions) toCheckThat nextCharOf"CODINGNINJA"IsPresentThereOrNot                                                                                                                                                 
                                                                                                                             
bool isPresent(vector<vector<char>> &M, int i, int j, int n, int m, string str, bool **visited)
{
    if(str.size()==0)
    return 1;
                                                                                                                                                   
    bool r=0;                 
    visited[i][j] = 1;
    
    if(i-1>=0 && M[i-1][j]==str[0] && !visited[i-1][j] && r==0)
    r = isPresent(M,i-1,j,n,m,str.substr(1),visited);
    
    if(j-1>=0 && M[i][j-1]==str[0] && !visited[i][j-1] && r==0)
    r = isPresent(M,i,j-1,n,m,str.substr(1),visited);
    
    if(i-1>=0 && j-1>=0 && M[i-1][j-1]==str[0] && !visited[i-1][j-1] && r==0)
    r = isPresent(M,i-1,j-1,n,m,str.substr(1),visited);
    
    if(i+1<n && M[i+1][j]==str[0] && !visited[i+1][j] && r==0)
    r = isPresent(M,i+1,j,n,m,str.substr(1),visited);
    
    if(j+1<m && M[i][j+1]==str[0] && !visited[i][j+1] && r==0)
    r = isPresent(M,i,j+1,n,m,str.substr(1),visited);
    
    if(i+1<n && j+1<m && M[i+1][j+1]==str[0] && !visited[i+1][j+1] && r==0)
    r = isPresent(M,i+1,j+1,n,m,str.substr(1),visited);
    
    if(i-1>=0 && j+1<m && M[i-1][j+1]==str[0] && !visited[i-1][j+1] && r==0)
    r = isPresent(M,i-1,j+1,n,m,str.substr(1),visited);
    
    if(i+1<n && j-1>=0 && M[i+1][j-1]==str[0] && !visited[i+1][j-1] && r==0)
    r = isPresent(M,i+1,j-1,n,m,str.substr(1),visited);
    
    visited[i][j] = 0;
    return r;
}
  
bool searchPathStoringGivenWordInMatrix(vector<vector<char>> &board, int n, int m)
{
	string str="CODINGNINJA";                                     // storing word "CODINGNINJA" in a string (index=0 to index=10)                                                       
	                                                 
	bool **visited = new bool*[n];                            
	for(int i=0; i<n; i++)
	{  visited[i] = new bool[m];
	   for(int j=0; j<m; j++)
	   visited[i][j] = 0;  }
	   
	for(int i=0; i<n; i++)
	{  for(int j=0; j<m; j++)
	   {
	   	 if(board[i][j] != 'C')
	   	 continue;
	   	 
	   	 if(isPresent(board,i,j,n,m,str.substr(1),visited))
	   	 return 1;                                                // doFunctionCall toCheckWholeWordIsPresentOrNot ifChar'C'IsFound                           
	   }
    }
	
	return 0;
}


int main()
{
    string s1 = "CXDXNXNXNXA";                        
    string s2 = "XOXIXGXIXJX";           
    
	vector<vector<char>> board;                                   // storing input matrix of uppercase english alphabets
	
	vector<char> v1; 
	for(int i=0; i<s1.size(); i++)
	v1.push_back(s1[i]); 
	board.push_back(v1);

	vector<char> v2; 
	for(int i=0; i<s2.size(); i++)
	v2.push_back(s2[i]); 
	board.push_back(v2);

    cout<<"Is 'CODINGNINJA' word present in board: ";
    cout<<searchPathStoringGivenWordInMatrix(board,2,11)<<endl;                    
}


/*

 C   X   D   X   N   X   N   X   N   X   A
  \     /  \   /   \   /   \   /   \   /  
   \   /    \ /     \ /     \ /     \ /    
 X   O   X   I   X   G   X   I   X   J   X
    
*/











