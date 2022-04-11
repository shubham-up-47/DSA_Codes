#include <bits/stdc++.h>
using namespace std;
 
 // Selection Sort: find index min element from unsorted array & put at front
   
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}
 
void selectionSort(int *arr, int n)                                                                                       
{ 

	for(int i=0; i<n; i++)
	{ 
		int minI = i;
		for(int j=i+1; j<n; j++)
		{
		   if(arr[j] < arr[minI])
		   minI = j;
		}
		 
		swap(arr, i, minI);
	}
	 
	 
}


int main()
{
	
   int arr[10] = {3,37,41,14,22,7,9,0,2,53};
 
   selectionSort(arr, 10);                   // sorting given array { O(n²) }  
     
   for(int i=0; i<10; i++)
   cout<<arr[i]<<" "; 
   
}














