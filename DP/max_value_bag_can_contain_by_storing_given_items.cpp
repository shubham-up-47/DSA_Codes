#include <bits/stdc++.h>
using namespace std;

// [Knapsack Problem]                                  
// finding max value that bag (can bear max W weight) can contain, by storing some items of n given items (each item has (value,weight)) 
// arr[i][j] = maxValue can be stored in bag when (i = no of items) & (j = maxWeight that bag can bear)
                                                                             
int maxValueBagCanContainBF(int *W, int *V, int n, int wMax)                                // Brute Force { O(2^n) } 
{
	if(n==0 || wMax==0)       
	return 0;
	           
			                                     
	int vMax1=INT_MIN, vMax2=INT_MIN;
	
	if(wMax-W[n-1] >= 0)                                                                     // including weight at index (n-1) 
	vMax1 = V[n-1] + maxValueBagCanContainBF(W, V, n-1, wMax-W[n-1]);                                
 
    vMax2 = maxValueBagCanContainBF(W, V, n-1, wMax);                                       // excluding weight at index (n-1)            
	    
		                                        
	return max(vMax1, vMax2);
}
                                                           
int maxValueBagCanContainM(int *W, int *V, int n, int wMax, int **arr)                      // Memorization { O(m*n) }
{
	if(n==0 || wMax==0)       
	return 0;
	else if(arr[n][wMax] != -1)
	return arr[n][wMax];
	           
			                                     
	int vMax1=INT_MIN, vMax2=INT_MIN;
	
	if(wMax-W[n-1] >= 0)                                                                     // including weight at index (n-1) 
	vMax1 = V[n-1] + maxValueBagCanContainM(W, V, n-1, wMax-W[n-1], arr);                                
 
    vMax2 = maxValueBagCanContainM(W, V, n-1, wMax, arr);                                   // excluding weight at index (n-1)            
	    
		                                        
	arr[n][wMax] = max(vMax1, vMax2);                               
	return arr[n][wMax];
}
                                                              
                                                                                                   
int main()
{
	int n=5, wMax=16, W[5]={10,3,2,5,20}, V[5]={5,7,1,0,8};
	cout<<"Max value that bag can contain, by storing some items of n given items, is:"<<endl;
                                                      
													           	
    cout<<maxValueBagCanContainBF(W, V, n, wMax)<<endl;
                                           
                                         	
	int **arr1 = new int*[n+1];
	for(int i=0; i<n+1; i++)
	{   arr1[i] = new int[wMax+1]; 
	    for(int j=0; j<wMax+1; j++)
	    arr1[i][j] = -1;    }
    cout<<maxValueBagCanContainM(W, V, n, wMax, arr1)<<endl; 
                    
                    
    int **arr2 = new int*[n+1];                                                             // Dynamic Programming { O(m*n) }
	for(int i=0; i<n+1; i++)
	arr2[i] = new int[wMax+1]; 
	 
	arr2[0][0] = 0;
	for(int i=1; i<n+1; i++)
	arr2[i][0] = 0; 
	for(int j=1; j<wMax+1; j++)
	arr2[0][j] = 0; 
	for(int i=1; i<n+1; i++)                                                                // i=current_n, j=current_wMax
	{   for(int j=1; j<wMax+1; j++)             
        {	
         	int vMax1=INT_MIN, vMax2=INT_MIN;
	
        	if(j-W[i-1] >= 0)                                                                // including weight at index (i-1) 
         	vMax1 = V[i-1] + arr2[i-1][j-W[i-1]];                              
 
            vMax2 = arr2[i-1][j];                                                           // excluding weight at index (i-1)            
	                       
	        arr2[i][j] = max(vMax1, vMax2);       
		}
    }
    cout<<arr2[n][wMax]<<endl; 
}
 

 





