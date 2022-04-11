#include <bits/stdc++.h>
using namespace std;

 // finding length of max sum subsequence of non consecutive elements in given array           
                                                                                               
int lengthOfMaxSumSubsequenceOfNonConsecutiveElementsBF(int *brr, int n)                    // Brute Force { O(2^n) } 
{
	if(n<=0)        
	return 0;                       
                                                                                                                                                                
    int r1 = brr[n-1] + lengthOfMaxSumSubsequenceOfNonConsecutiveElementsBF(brr, n-2);      // including arr[n-1] 
    int r2 = lengthOfMaxSumSubsequenceOfNonConsecutiveElementsBF(brr, n-1);                 // excluding arr[n-1] 
	                                                                                                                                              
	return max(r1,r2);
}
                                                                                           
int lengthOfMaxSumSubsequenceOfNonConsecutiveElementsM(int *arr, int *brr, int n)           // Memorization { O(n) }
{
	if(n<=0)    
	return 0;     
    else if(arr[n]!=-1)
	return arr[n];	
                                                                                                                         
    int r1 = brr[n-1] + lengthOfMaxSumSubsequenceOfNonConsecutiveElementsM(arr, brr, n-2);  // including arr[n-1] 
    int r2 = lengthOfMaxSumSubsequenceOfNonConsecutiveElementsM(arr, brr, n-1);             // excluding arr[n-1] 
	                                                                                                                                              
	arr[n] = max(r1,r2);          
	return arr[n];
}
                         

int main()
{
	int n=7, brr[]={4,1,5,2,3,7,6};
	cout<<"Length of max sum subsequence of non consecutive elements is: "<<endl;
	
    cout<<lengthOfMaxSumSubsequenceOfNonConsecutiveElementsBF(brr, n)<<endl;
	
	int arr1[n+1];
	for(int i=0; i<n+1; i++)
	arr1[i] = -1; 
    cout<<lengthOfMaxSumSubsequenceOfNonConsecutiveElementsM(arr1, brr, n)<<endl; 
   
    int arr2[n+1];                                                                          // Dynamic Programming { O(n) }
    arr2[0] = brr[0];
	arr2[1] = max(brr[0], brr[1]); 
    for(int i=2; i<n+1; i++)
    {
       int r1 = brr[i-1] + arr2[i-2];                                                       // including arr[i-1] 
       int r2 = arr2[i-1];                                                                  // excluding arr[i-1] 
	                                                                                                                                              
	   arr2[i] = max(r1,r2);    
    } 
    cout<<arr2[n]<<endl; 
}










 




