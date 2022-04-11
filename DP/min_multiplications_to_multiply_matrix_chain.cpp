#include <bits/stdc++.h>
using namespace std;
                                                                                                 
 // finding min no of multiplications done to multiply matrix chain of given n matrices
 // Dimentions of (i)th matrix = p[i-1] X p[i]              { p[n+1] = given array of size (n+1) }
 // multiplying matrix (nXm) & (mXp) gives (nXp) matrix & requires (nXmXp) operations    
 // arr[i][j] = min multiplications done to multiply matrix (i) & matrix (j)                                                   
                                                                                                          
 int minMultiplicationsDoneToMultiplyMatrixChain(int *p, int i, int j, int **arr)
 {
 	if(i==j)
 	return 0;
 	else if(arr[i][j] != -1)
 	return arr[i][j];
                                                                      
 	int minM = INT_MAX;
 	for(int k=i; k<j; k++)
 	{  int a = minMultiplicationsDoneToMultiplyMatrixChain(p, i, k, arr);      // min multiplications from matrix (i) to matrix (k)         
 	   int b = minMultiplicationsDoneToMultiplyMatrixChain(p, k+1, j, arr);    // min multiplications from matrix (k+1) to matrix (j)     
 	   
 	   minM = min(minM, a+b+p[i-1]*p[k]*p[j]);  }                              // multiplying matrix [(i-1)X(k)] & [(k)X(j)]     
		                 
	arr[i][j] = minM; 
    return arr[i][j];
}
                                                                   
                                                                                                                                    
int main()
{
	int n=3, p[4]={10, 15, 20, 25};                 
	         
    int **arr = new int*[n+1];                                                 // Dynamic Programming   
    for(int i=0; i<n+1; i++)                                                     
    {  arr[i] = new int[n+1];    
       for(int j=0; j<n+1; j++)
       arr[i][j] = -1;  }
     
	cout<<"Min no of multiplications done to multiply given matrix chain is: ";
    cout<<minMultiplicationsDoneToMultiplyMatrixChain(p, 1, n, arr)<<endl; 
}





  
  
  
  
