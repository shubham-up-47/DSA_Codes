#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{ 
	int arr1D[3] = {3,6,9};                             // 1D static array
	 
	for(int i=0; i<3; i++)
	cout<<arr1D[i]<<" "; 
    cout<<endl<<endl;
    
    
    
	int *arr1D_d = new int[3];                          // 1D dynamic array
	 
	for(int i=0; i<3; i++)
	{  arr1D_d[i] = arr1D[i];
	   cout<<arr1D_d[i]<<" ";   }
    cout<<endl<<endl;
    
    
    
	int arr2D[3][2] = {{3,1}, {6,3}, {7,2}};            // 2D static array
	
	for(int i=0; i<3; i++)
	{  for(int j=0; j<2; j++)
	   cout<<arr2D[i][j]<<" ";
	   cout<<endl;   }  
	cout<<endl;   
	
	
	
	int **arr2D_d = new int*[3];                        // 2D dynamic array
	
	for(int i=0; i<3; i++)
	{  arr2D_d[i] = new int[2];
	   for(int j=0; j<2; j++)
	   {  arr2D_d[i][j] = arr2D[i][j];
	      cout<<arr2D_d[i][j]<<" ";   }
	   cout<<endl;   } 
	cout<<endl;



	int **arr = new int*[3];                            // Ladder array (2D dynamic array)                                   
	
	for(int i=0; i<3; i++)
	{  arr[i] = new int[i+1];
	   for(int j=0; j<2 && j<(i+1); j++)
	   {  arr[i][j] = arr2D[i][j];
	      cout<<arr[i][j]<<" ";   }
	   cout<<endl;   } 
	cout<<endl; 
	
	
	
	delete []arr1D_d;                                   // deleting 1D array    
	
	for(int i=0; i<3; i++)                              // deleting 2D array
	delete []arr2D_d[i];
	delete []arr2D_d;
	
	for(int i=0; i<3; i++)
	delete []arr[i];
	delete []arr;
}                                                       // dont forget to delete DMA at end   



//                       [ SMA = static memory allocation ] & [ DMA = dynamic memory allocation ]              
// SMA = (stored in stack), (accessed using variable), (generally its size is a constant), (it is deleted after program ends)       
// DMA = (stored in heap), (accessed using pointer), (generally its size is a variable), (it is occupied until we delete it)    

















