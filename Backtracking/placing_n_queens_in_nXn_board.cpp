#include <bits/stdc++.h>
using namespace std;


bool isValidSpot(vector<vector<int>> &board, int n, int currR, int currC)   // checking that the queen can be placed on (board[currR][currC]) or not
{
	for(int i=currR-1; i>=0; i--)                                           // checking any queen or not in column  
	{  if(board[i][currC]==1) 
	   return 0;  }
	   
	for(int i=currR-1,j=currC-1;  i>=0&&j>=0;  i--,j--)                     // checking any queen or not in upper left diagonal  
	{  if(board[i][j]==1)
	   return 0;  } 
	
	for(int i=currR-1,j=currC+1;  i>=0&&j<n;  i--,j++)                      // checking any queen or not in upper right diagonal   
	{  if(board[i][j]==1)
	   return 0;  } 
	                                                                                      
	return 1;
}
                                       
void placeNQueens(vector<vector<int>> &board, int n, int currR)             // currR = current row, currC = current column
{
	if(currR==n)
	{  cout<<endl;
	   for(int i=0; i<n; i++)
	   {  for(int j=0; j<n; j++)
          cout<<board[i][j]<<" ";   
		  cout<<endl;  }
	   return;	 }
	
	for(int currC=0; currC<n; currC++) 
	{
		if(isValidSpot(board, n, currR, currC))
		{  board[currR][currC] = 1;                                         // place at eligible spot, then recursive call for rest 
		   placeNQueens(board, n, currR+1);
		   board[currR][currC] = 0;	}                                       // backtrack & unplace that spot to check for other columns 
	}
	
	return;                                                                 // if no eligible spot found in currR, then backtrack   
}

int main()
{ 
	int n;
	cin>>n;

	vector<vector<int>> board(n, vector<int>(n,0));                         // given n X n matrix         
	
	placeNQueens(board, n, 0); 
}


/*

4

*/


/*

0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

*/






