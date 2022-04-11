#include <bits/stdc++.h>
using namespace std;
  
  // Bubble Sort: each time travel from (0) to (n-i) & do swapping when wrong order
  
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}
 
 
void bubbleSort(int *arr, int n)                                                                                      
{ 
	for(int i=0; i<n; i++)
	{ 	
	    for(int j=1; j<n-i; j++)
		{ 	
		    if(arr[j-1] > arr[j])
			swap(arr, j-1, j); 	
		} 
		
	}  
	
}


int main()
{
	
   int arr[10] = {3,37,41,14,22,7,9,0,2,53};
 
   bubbleSort(arr, 10);              // sorting given array { O(n²) }  
   
   for(int i=0; i<10; i++)
   cout<<arr[i]<<" "; 
   
}


















