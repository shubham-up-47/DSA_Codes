#include <bits/stdc++.h>
using namespace std;

 // finding laragest square with all zeros, in the matrix storing binary   
 // arr[i][j] = size of laragest square with all zeros, ending at M[i][j]       
                                                      
int main()
{
	int m=4, n=5, M[4][5]={ {0,1,1,0,0}, {0,0,0,1,0}, {0,0,0,1,0}, {0,0,0,0,0} };
	        
	        
    int arr[m][n];                                                           // Dynamic Programming  
    arr[0][0] = (M[0][0]==0) ? 1 : 0; 
    for(int i=1; i<m; i++)                                            
    arr[i][0] = (M[i][0]==0) ? 1 : 0; 
    for(int j=1; j<n; j++)                                                 
    arr[0][j] = (M[0][j]==0) ? 1 : 0;    
       
	int maxS = 0; 
    for(int i=1; i<n; i++)
    {  for(int j=1; j<m; j++)
       {
       	  if(M[i][j]==0)
       	  arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j],arr[i][j-1])) + 1;
       	  else
          arr[i][j] = 0;
	   
	      maxS = max(maxS, arr[i][j]);
       }
    }
    
    
	cout<<"Size of laragest square with all zeros, in the matrix storing binary  is: ";
    cout<<maxS<<endl; 
}

















