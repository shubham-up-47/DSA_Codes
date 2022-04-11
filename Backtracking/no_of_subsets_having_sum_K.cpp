#include <bits/stdc++.h>
using namespace std;

int subArrayHavingSumK(int arr[], int n, int sum)
{
	if(n==0)                                           // all the subsets of the given array have been checked               
	return ((sum==0) ? 1 : 0);
	
	sum = sum - arr[n-1];                              // including arr[n-1] in subarray                
	int c1 = subArrayHavingSumK(arr, n-1, sum);
	
	sum = sum + arr[n-1];                              // excluding arr[n-1] in subarray                                   
	int c2 = subArrayHavingSumK(arr, n-1, sum);
	
	return (c1 + c2);
}


int main()
{ 
	int t;                                             // no of test cases                           
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		int arr[n];
		for(int i=0; i<n; i++)
		cin>>arr[i];
		
		cout<<subArrayHavingSumK(arr, n, k)<<endl;     // printing (no of subarray having elements sum k) for (given input array)                      
    } 
}


/*

1
5 6
2 4 4 3 1

*/












