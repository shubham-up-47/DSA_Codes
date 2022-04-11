#include <bits/stdc++.h>
using namespace std;

 // if (sum till 'i'th index) == (sum till 'j'th index), then subarray between i & j will have 0 sum                                                                   
                                          
int longestSubarrayHavingSumZero(int *arr, int n)
{
	int rangeL = 0;
	unordered_map<int,int>  h;                                // (Key,Value) = (sum till arr[i], i)  
	
	for(int i=1; i<n; i++)                                    // arr[i] = (sum till 'i'th index)               
	arr[i] += arr[i-1];  
	
	for(int i=0; i<n; i++)                 
	{  
	   if(arr[i]==0 && i+1 > rangeL)
	   rangeL = i+1; 
	   else if(h.count(arr[i]) > 0 && i-h[arr[i]] > rangeL)   // if (previous sum appears again) & (length is larger), then update rangeL
	   rangeL = i-h[arr[i]];
	   if(h.count(arr[i])==0)                                 // store (Key,Value) = (sum,index) in HashMap  
	   h[arr[i]] = i;  
	}                                                      
	
	return rangeL;
}


int main()
{
	int n;                                                             
	cout<<"Enter size of array: ";                     
	cin>>n;
	
	int *arr = new int[n];
	cout<<"Enter array elements: "; 
	for(int i=0; i<n; i++)
	cin>>arr[i];
	 
	cout<<"\n\nLength of longest subarray having sum=0 is: "<< longestSubarrayHavingSumZero(arr,n) <<endl<<endl;
}
 
 
 
/*

  10    1 0 -9 2 9 -1 -1 -1 7 0 
  
*/

 


 
 
 
