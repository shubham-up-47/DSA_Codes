#include <bits/stdc++.h>
using namespace std;

      // FOR ANY ARRAY

int linearSearch_iterative(int *arr, int n, int x)           // searching a element in a unsorted array { O(n) }                                                                                 
{
	for(int i=0; i<n; i++)
	{
	   if(arr[i] == x)
	   return i;	
	}
	
	return -1; 
}


int main()
{
	
   int arr[10] = {0,2,3,7,9,14,22,37,41,53};
 
   cout << linearSearch_iterative(arr, 10, 7); 
   
}















