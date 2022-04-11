#include <bits/stdc++.h>
using namespace std;
 
 // Merge Sort: Sort left half array & right half array by recursion, then merge sorted arrays                          
 
void mergeSortedArrays(int *arr, int si, int mid, int ei)
{
	int n = ei-si+1;
	int *a = new int[n];
	
	for(int i=si,j=mid+1,k=0; k<n; k++)
	{ 
		if( (i<=mid && j<=ei && arr[i]<arr[j]) ||  (i<=mid && j>ei) )
	    a[k] = arr[i++];  
		else  
	    a[k] = arr[j++];   
	}
	 
	for(int i=si,j=0; i<=ei; i++,j++)
	arr[i] = a[j]; 
	
	delete []a;
}
 

void  mergeSort(int *arr, int si, int ei)
{
	if(si>=ei)
	return;
	
	 
	int mid = (si+ei)/2;
	
	mergeSort(arr, si, mid);
	mergeSort(arr, mid+1, ei);
	
	mergeSortedArrays(arr, si, mid, ei);
	
	
	return;
}


int main()
{ 
   int arr[10] = {3,37,41,14,22,7,2,0,2,53};
 
   mergeSort(arr, 0, 9);            // sorting given array { O(nlogn) }  
   
   for(int i=0; i<10; i++)
   cout<<arr[i]<<" ";  
}




















