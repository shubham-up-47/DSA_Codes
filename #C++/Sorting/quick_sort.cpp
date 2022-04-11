#include <bits/stdc++.h>
using namespace std;
 
 // Quick Sort: Sort left array (elements less than pivot) & right array (elements greater than equal to pivot) by recursion 
 
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}                      
  
int createPartition(int *arr, int si, int ei)
{
	int pivotI = si; 
 
	for(int i=si+1, j=ei;  i<=j;  )
	{   while(arr[i] <= arr[pivotI])
	    i++; 
	    while(arr[j] > arr[pivotI])     
	    j--;
	
	    if(i<=j)
    	swap(arr, i, j);
		else
		{  swap(arr, pivotI, j);    // swap with j bcz currently (arr[i]>=arr[pivotI]) && (arr[j]<arr[pivotI]) && (i>j)  
           pivotI = j;  }    }
	 
	return pivotI;
}
 

void  quickSort(int *arr, int si, int ei)
{
	if(si>=ei)
	return;
	 
	int pivotI = createPartition(arr, si, ei); 
	quickSort(arr, si, pivotI-1);
	quickSort(arr, pivotI+1, ei);
	  
	return;
}


int main()
{ 
   int arr[7] = {11, 3, 14, 3, 7, 14, 2};
 
   quickSort(arr, 0, 6);            // sorting given array { O(nlogn) }  
   
   for(int i=0; i<7; i++)
   cout<<arr[i]<<" ";  
}






















