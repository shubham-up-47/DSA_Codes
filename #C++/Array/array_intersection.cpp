#include <bits/stdc++.h>
using namespace std;


void printArrayIntersection(int *arr1, int n1, int *arr2, int n2)         // printing intersection of given two arrays  { O(mlogm+nlogn) }
{
	sort(arr1, arr1+n1);
	sort(arr2, arr2+n2);
	
	for(int i=0,j=0; i<n1&&j<n2; )
	{  
	   if(arr1[i] < arr2[j])
	   i++;
	   else if((arr1[i] > arr2[j]))
	   j++;	
	   else
	   {  cout<<arr1[i]<<" ";
	      i++; j++;  } 
	} 
}


int main()
{
   int arr1[5]={9,5,7,1,6}, arr2[7]={0,1,7,2,8,5,2}; 	
   
   printArrayIntersection(arr1, 5, arr2, 7); 
}
























