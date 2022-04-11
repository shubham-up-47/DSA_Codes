#include <bits/stdc++.h>
using namespace std;

      // ONLY FOR SORTED ARRAY

int binarySearch_iterative(int *arr, int n, int x)           // searching a element in a sorted array { O(logn) }                                                                                 
{
	int si=0, ei=n-1;
	
	while(si<=ei)
	{  int mid = (si+ei)/2;
	   
	   if(arr[mid] == x)
	   return mid;
	   else if(arr[mid] > x)
	   ei = mid-1;
	   else
	   si = mid+1;	}
	
	return -1; 
}


int main()
{
	
   int arr[10] = {0,2,3,7,9,14,22,37,41,53};
 
   cout << binarySearch_iterative(arr, 10, 7); 
   
}










 






