#include <bits/stdc++.h>
using namespace std;

// splitting given array in 2 equal sum subsets where (elements divisible by 5 lie in subset1) & (elements divisible by 3 but not by 5 lie in subset2)

int splitInEqualSumSubsets(int *arr, int n, int sum1=0, int sum2=0)                                            
{
    if(n==0)
    return (sum1==sum2); 
    else if(arr[n-1]%5==0)
    return splitInEqualSumSubsets(arr, n-1, sum1+arr[n-1], sum2);
    else if(arr[n-1]%3==0 && arr[n-1]%5!=0)
    return splitInEqualSumSubsets(arr, n-1, sum1, sum2+arr[n-1]); 
    
 
    int c=0; 
    c += splitInEqualSumSubsets(arr, n-1, sum1+arr[n-1], sum2); 
    c += splitInEqualSumSubsets(arr, n-1, sum1, sum2+arr[n-1]); 
 
 
    return c;	
}


int main()
{ 
    int n=5;
	int arr[5] = {1,2,3,4,2};
 
	cout<<splitInEqualSumSubsets(arr, n); 
}


























