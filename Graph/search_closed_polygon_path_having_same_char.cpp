#include <bits/stdc++.h>
using namespace std;

// best & important ans so mug this method & steps                                                                                     

bool hasCycle(vector<vector<char>> &M, int i, int j, int n, int m, char c, vector<vector<bool>> &visited, int iPrev, int jPrev)
{
    if(visited[i][j]==1)
    return 1;
                           
    bool r=0;
    visited[i][j] = 1;
    int arr1[]={-1,0,1,0}, arr2[]={0,-1,0,1};                                     // using arr1, arr2 to move in 4 directions for searchig cycle            
                   
    for(int k=0; k<4; k++)                                                                
	{
	   int iNext=i+arr1[k], jNext=j+arr2[k];
	   if(iNext>=0 && jNext>=0 && iNext<n && jNext<m && M[iNext][jNext]==c && r==0 && (iNext!=iPrev || jNext!=jPrev))
       r = hasCycle(M,iNext,jNext,n,m,c,visited,i,j);
    }
                        
    return r;
}

bool searchClosedPolygonPathHavingSameChar(vector<vector<char>> &board, int n, int m)
{ 
	vector<vector<bool>> visited(n, vector<bool>(m,false));                       // mug this to make 2D initialized array in 1 line            
 
	for(int i=0; i<n; i++)
	{  for(int j=0; j<m; j++)
	   {
	   	 if( !visited[i][j] && hasCycle(board,i,j,n,m,board[i][j],visited,-1,-1) )
	   	 return 1;
	   }
    }
	                    
	return 0;
}


int main()
{
    string s1 = "AAAAD";
    string s2 = "ABAAE";
    string s3 = "AAACF";
    
	vector<vector<char>> board; 
	
	vector<char> v1; 
	for(int i=0; i<s1.size(); i++)
	v1.push_back(s1[i]); 
	board.push_back(v1);

	vector<char> v2; 
	for(int i=0; i<s2.size(); i++)
	v2.push_back(s2[i]); 
	board.push_back(v2);
	
	vector<char> v3; 
	for(int i=0; i<s3.size(); i++)
	v3.push_back(s3[i]); 
	board.push_back(v3);

    cout<<"Is closed polygon path having same char present in board: ";        
    cout<<searchClosedPolygonPathHavingSameChar(board,3,5)<<endl;                 // checking that a rightAngledPolygonOfSameChar is present or not        
}


/*

 A---A---A---A   D
 |           |
 A   B   A---A   E
 |       |  
 A---A---A   C   F
    
*/










