#include <bits/stdc++.h>
using namespace std;

 
int* mergeSortedArrays(int arr1[], int n1, int arr2[], int n2)
{
	int *arr = new int[n1+n2];
	
	for(int i=0,j=0,k=0; k<n1+n2; k++)
	{ 
		if( (i<n1 && j<n2 && arr1[i]<arr2[j]) ||  (i<n1 && j>=n2) )
		{  arr[k] = arr1[i]; 
		   i++;  }
		else  
		{  arr[k] = arr2[j];  
		   j++;  }
	}
	 
	return arr;
}


int main()
{
	
   int arr1[] = {0, 2, 3, 7, 9, 14, 22};
   int arr2[] = {1, 4, 7, 8, 14, 25, 37, 41, 53};
    
   int *arr = mergeSortedArrays(arr1, 7, arr2, 9);                   // merging given sorted arrays { O(n1+n2) }  
     
   for(int i=0; i<16; i++)
   cout<<arr[i]<<" "; 
   
}



















