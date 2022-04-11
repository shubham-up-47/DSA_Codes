#include <bits/stdc++.h>
using namespace std;

int fact(int n, int *arr)     // Memorization { here O(Memorization) = O(Brute Force) }
{
  if(n==0)
  return 1;
  else if(arr[n]!=-1)
  return arr[n];
  	
  arr[n] = n*fact(n-1,arr);
  
  return arr[n]; 	 
}

int main()
{
   int n=6;	
   
   int arr[n+1];
   for(int i=0; i<n+1; i++)
   arr[i] = -1;
 
   cout<<fact(n, arr); 
}








