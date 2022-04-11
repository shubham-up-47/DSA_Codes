#include <bits/stdc++.h>
using namespace std;

                                          
int countPairsHavingDifferenceK(int *arr, int n, int k)
{
	int count = 0;
	unordered_map<int,int>  h;
	
	for(int i=0; i<n; i++)                               // storing frequency of each element               
	h[arr[i]]++;  
	
	for(int i=0; i<n; i++)                 
	{  h[arr[i]]--;                                      // remove freaquency from arr[i]
	
	   if(k!=0)                                          // count no of unvisited elements, which can form required pair with arr[i]
	   count += h[arr[i]-k] + h[arr[i]+k]; 
	   else
	   count += h[arr[i]];  }                          
	
	return count;
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
	
	int k;                                                             
	cout<<"Enter K value: ";                     
	cin>>k;
	 
	cout<<"\n\nCount of integer pairs having Difference="<<k<<" is: "<< countPairsHavingDifferenceK(arr,n,k) <<endl<<endl;
}
 
 
/*

  10    1 3 -2 2 9 4 8 5 7 0    2
  
*/

 












