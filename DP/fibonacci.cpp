#include <bits/stdc++.h>
using namespace std;


int fibBF(int n)                              // Brute Force { O(2^n) }
{
  if(n==0 || n==1)
  return n; 
  
  int r = fibBF(n-1) + fibBF(n-2);
  
  return r; 	 
}

int fibM(int n, int *arr)                     // Memorization { O(n) }
{
  if(n==0 || n==1)
  return n;
  else if(arr[n]!=-1)
  return arr[n];
  	
  arr[n] = fibM(n-1,arr) + fibM(n-2,arr);
  
  return arr[n]; 	 
}


int main()
{
   int n=6;	
   cout<<n<<"th Fibonacci number is:"<<endl;
   
   cout<<fibBF(n)<<endl;
   
   int arr1[n+1];
   for(int i=0; i<n+1; i++)
   arr1[i] = -1; 
   cout<<fibM(n, arr1)<<endl;
   
   int arr2[n+1];                             // Dynamic Programming { O(n) }
   arr2[0] = 0;
   arr2[1] = 1;
   for(int i=2; i<n+1; i++)
   arr2[i] = arr2[i-1] + arr2[i-2]; 
   cout<<arr2[n]<<endl; 
}











