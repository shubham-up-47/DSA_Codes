#include <bits/stdc++.h>
using namespace std;

                                          
void printArrayIntersection(int *arr1, int n1, int *arr2, int n2)
{
	unordered_map<int,int>  h;
	
	for(int i=0; i<n1; i++)
	h[arr1[i]]++;
                                                                              	
	for(int i=0; i<n2; i++)
	{  
	   if(h[arr2[i]] > 0)
	   {  cout<<arr2[i]<<" ";
	      h[arr2[i]]--;  }  
	} 
}
  
  
int main()
{
	int n1;                                                             
	cout<<"Enter size of array1: ";                     
	cin>>n1; 
	int *arr1 = new int[n1];
	cout<<"Enter array1 elements: "; 
	for(int i=0; i<n1; i++)
	cin>>arr1[i];
	
	int n2;                                                             
	cout<<"\nEnter size of array2: ";                     
	cin>>n2; 
	int *arr2 = new int[n2];
	cout<<"Enter array2 elements: "; 
	for(int i=0; i<n2; i++)
	cin>>arr2[i];
	
	cout<<"\n\n\nIntersection elements of 2 arrays (in the order they appear in 2nd array): "; 
    printArrayIntersection(arr1, n1, arr2, n2); 
	cout<<endl<<endl;
}

  
/*

  8 1 4 2 2 8 9 1 7 
  9 5 3 7 2 1 9 3 1 7
    
*/

 












