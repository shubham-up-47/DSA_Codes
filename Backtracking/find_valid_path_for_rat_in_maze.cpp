#include <bits/stdc++.h>
using namespace std;
 
// currPath = current path, currR = current row, currC = current column

void findPath(vector<vector<int>> &maze, int n, vector<vector<int>> &currPath, int currR, int currC)
{
	if(currR==n-1 && currC==n-1)                                 // print when rat reaches to (end point) of the path         
	{  cout<<endl;
	   for(int i=0; i<n; i++)                                    // printing the (path followed by rat) as a matrix 0,1                  
	   {  for(int j=0; j<n; j++)
          cout<<currPath[i][j]<<" ";   
		  cout<<endl;  }
	   return;	 }
	else if(currR<0 || currC<0 || currR>=n || currC>=n)
	return;
	else if(maze[currR][currC]==0 || currPath[currR][currC]==1)  // if (current cell) is blocked or already included in (current path) 
	return;                                                      
	
	currPath[currR][currC] = 1;                                  // include (current cell) & call recursion, to consider current valid path 
	
	findPath(maze, n, currPath, currR-1, currC);                 // moving top
	findPath(maze, n, currPath, currR+1, currC);                 // moving down  
	findPath(maze, n, currPath, currR, currC-1);                 // moving left  
	findPath(maze, n, currPath, currR, currC+1);                 // moving right  
	
	currPath[currR][currC] = 0;                                  // backtrack & exclude (current cell), to consider other valid paths
	                                              
	return;
}

int main()
{ 
	int n;
	cin>>n;

	vector<vector<int>> maze(n, vector<int>(n));
	for(int i=0; i<n; i++)                                       // storing input maze           
	{  for(int j=0; j<n; j++)
       cin>>maze[i][j];	 }
       
	vector<vector<int>> currPath(n, vector<int>(n,0));           // stores path for rat to cross the maze   
	currPath[n-1][n-1] = 1;
	
	findPath(maze, n, currPath, 0, 0);                           // printing all possible paths for rat to cross the maze 
}


/*

3
1 1 0
1 1 1
1 1 1

*/


/*

1 0 0
1 1 1
1 1 1

1 0 0
1 0 0
1 1 1

1 0 0
1 1 0
0 1 1

1 0 0
1 1 1
0 0 1

1 1 0
0 1 0
0 1 1

1 1 0
1 1 0
1 1 1

1 1 0
0 1 1
0 0 1

*/









