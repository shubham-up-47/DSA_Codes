#include <bits/stdc++.h>
using namespace std;


void printArray(int *arr, int n)
{
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void rotateDleft(int *arr, int n, int d)       // rotating given array by 3 units (towards left)   { O(n) }
{
	reverse(arr, arr+n);   
	reverse(arr, arr+n-d);  
	reverse(arr+n-d, arr+n);  	 
}

void rotateDright(int *arr, int n, int d)      // rotating given array by 3 unit (towards right)   { O(n) }
{
	reverse(arr, arr+n);   
	reverse(arr, arr+d);  
	reverse(arr+d, arr+n);  	 
}


int main()              
{ 
    int n= 8, d=3;
	int arr[8] = {3,0,2,7,7,1,9,4};

	cout<<"Initial array: ";  
    printArray(arr,n);  
    
    rotateDleft(arr, n, d);   
	cout<<"\nRotating by 3 (towards left): ";                                                             
    printArray(arr,n);  
    rotateDright(arr, n, d); 
	cout<<"Rotating by 3 (towards right): ";                                                                    
    printArray(arr,n);  
    
	cout<<"\nFinal array: ";  
    printArray(arr,n); 
}

























