#include <bits/stdc++.h>
using namespace std;

 // count no of ways to cross (n steps staircase) when (1/2/3 steps move are allowed at a time)

int staircase(int *arr, int n)          // Memorization { here O(Memorization) < O(Brute Force) }
{
	if(n==0||n==1||n==2)
	return (n==2) ? 2 : 1;
    else if(arr[n]!=-1)
	return arr[n];	
	
	arr[n] = staircase(arr,n-1) +staircase(arr,n-2) + staircase(arr,n-3);
	
	return arr[n];
}


int main()
{
	int n=7;
	
	int arr[n+1];
	for(int i=0; i<n+1; i++)
	arr[i] = -1;
	
    cout<<staircase(arr, n); 
}















 





