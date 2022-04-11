#include <bits/stdc++.h>
using namespace std;

 // finding length of longest strictly increasing subsequence in given array    
 // arr[i] = length of longest strictly increasing subsequence ending at index 'i' in given array       
   
int main()
{
	int n=7, brr[]={4,1,5,2,3,7,6};
	
	 
    int arr[n];                                                           // Dynamic Programming  
    arr[0] = 1; 
    for(int i=1; i<n; i++)
    {
       arr[i] = 1;
	   for(int j=i-1; j>=0; j--)
	   {  if(brr[j]<brr[i] && arr[j]>=arr[i])
	      arr[i] = arr[j] + 1;   }	 
    } 
    
    int maxL = 0;
    for(int i=0; i<n; i++)
    maxL = max(maxL, arr[i]);
    
	cout<<"Length of longest strictly increasing subsequence is: ";
    cout<<maxL<<endl; 
}










 




