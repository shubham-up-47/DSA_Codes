#include <bits/stdc++.h>
using namespace std;

                                          
int countPairsHavingSumZero(int *arr, int n)
{
	int count = 0;
	unordered_map<int,int>  h;
	
	for(int i=0; i<n; i++)                               // storing frequency of each element               
	h[arr[i]]++;  
	
	for(int i=0; i<n; i++)                 
	{  h[arr[i]]--;                                      // remove freaquency from arr[i]
	   count += h[-arr[i]];  }                           // count no of unvisited elements, which can form required pair with arr[i]
	
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
	 
	cout<<"\n\nCount of integer pairs having sum=0 is: "<< countPairsHavingSumZero(arr,n) <<endl<<endl;
}
 
 
/*

  10 1 0 -9 2 9 -1 -1 -1 7 0 
  
*/

 













