#include <bits/stdc++.h>
using namespace std;
 
  // CREATING NEW ARRAY TO STORE ELEMENTS IN GIVEN ORDER
 
 void  pushZerosAtEnd(int arr[], int n)                          // pushing all zeros at end & keepng order of occurence of non zeros same 
 {
 	int a[n] = {0};
 	
 	for(int i=0,j=0; i<n; i++)
 	{ 	if(arr[i]!=0)
        {  a[j] = arr[i];
		   j++;	 } 	  }
 	
 	for(int i=0; i<n; i++)
 	arr[i] = a[i]; 
 }
 
    // Example: 0110213 & 31015419
    
 int* arrayIntersection(int arr1[], int n1, int arr2[], int n2)  // storing common elements of 2 arrays in order same as they present in array 1                                                                                                     
 {
 	int n = max(n1,n2);
 	int *arr = new int[n];
 	
 	int k=0;
 	for(int i=0; i<n1; i++)
 	{  for(int j=0; j<n2; j++)
 	   { 
		  if(arr1[i]==arr2[j])
		  {   arr[k] = arr2[j];
			  arr2[j] = INT_MIN;                                 // storing -oo to avoid repetition while searching  
			  k++;   
			  break;   }		 
	   } 
	} 
	
	return arr;
 }
 
 
int main()
{ 
 
 
 
 
 
 
 
 
 
}









 





 








