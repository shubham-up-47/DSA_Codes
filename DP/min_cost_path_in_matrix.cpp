#include <bits/stdc++.h>
using namespace std;

const int M=2, N=3;

// for given matrix (matrix[m][n]), matrix[i][j] = cost of cell (i,j)  
// finding cost of the (minimum cost path), while moving from (0,0) to (m-1,n-1), where we can move (downward/rightward/alongDiagonal) only   
// arr[i][j] = cost of the min cost path on moving from (i,j) to (m-1,n-1)          
                                                    
int minCostPathInMatrixBF(int matrix[][N], int m, int n, int i=0, int j=0)                  // Brute Force { O(3^x) where x=max(m,n) } 
{
	if(i>=m || j>=n)       
	return INT_MAX;
	else if(i==m-1 && j==n-1)
	return matrix[i][j];
  
	int c1 = minCostPathInMatrixBF(matrix, m, n, i+1, j);
	int c2 = minCostPathInMatrixBF(matrix, m, n, i, j+1);
	int c3 = minCostPathInMatrixBF(matrix, m, n, i+1, j+1);
	                      
	return (min(c1, min(c2,c3)) + matrix[i][j]);
}
                                            
int minCostPathInMatrixM(int matrix[][N], int m, int n, int arr[][N], int i=0, int j=0)     // Memorization { O(m*n) }
{
	if(i>=m || j>=n)       
	return INT_MAX;
	else if(i==m-1 && j==n-1)       
	return matrix[i][j];
    else if(arr[i][j] != -1)
	return arr[i][j];	                                            
                                                                                                                                                                                                                             
	int c1 = minCostPathInMatrixM(matrix, m, n, arr, i+1, j);
	int c2 = minCostPathInMatrixM(matrix, m, n, arr, i, j+1);
	int c3 = minCostPathInMatrixM(matrix, m, n, arr, i+1, j+1);
	                      
	arr[i][j] = min(c1, min(c2,c3)) + matrix[i][j]; 
	return arr[i][j];
}
                                         
                                                                                                   
int main()
{
	int m=2, n=3;
	int matrix[M][N] = {{3,4,5},{6,7,8}}; 
	cout<<"Cost of the minimum cost path, while moving from (0,0) to (m-1,n-1) is: "<<endl;
                                                      
													           	
    cout<<minCostPathInMatrixBF(matrix, m, n)<<endl;
    
                                         	
	int arr1[M][N];
	for(int i=0; i<m; i++)
	{   for(int j=0; j<n; j++)
	    arr1[i][j] = -1;    }
     cout<<minCostPathInMatrixM(matrix, m, n, arr1)<<endl; 
                    
                    
    int arr2[M][N];                                                                         // Dynamic Programming { O(m*n) }
    arr2[m-1][n-1] = matrix[m-1][n-1]; 
	for(int i=m-1; i>=0; i--)
	for(int j=n-1; j>=0; j--)
    {	int c1=INT_MAX, c2=INT_MAX, c3=INT_MAX; 
    
        if(i==m-1 && j==n-1)
        continue; 
	    if(i+1 < m)
	    c1 = arr2[i+1][j];
	    if(j+1 < n)
	    c2 = arr2[i][j+1];
	    if(i+1 < m && j+1 < n)
	    c3 = arr2[i+1][j+1];
	                  
    	arr2[i][j] = min(c1, min(c2,c3)) + matrix[i][j];   } 
    cout<<arr2[0][0]<<endl; 
}


// THIS CODE TELLS BEST WAY TO PASS STATIC 2D ARRAY AS ARGUMENT











 

