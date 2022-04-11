#include <bits/stdc++.h>
using namespace std;
                                                           
  // ConsecutiveNumbers of (i) are ....(i-2), (i-1), (i), (i+1), (i+2)....  
  // start = starting number of current sequence of consective numbers   
  // startL = starting number of longest(L) sequence of consective numbers                                                               
                                                                                
vector<int> longestSubsequenceOfConsecutiveNumbers(int *arr, int n)
{
	vector<int> r;
	int start, range, startL, rangeL;                        
	unordered_map<int,bool>  h;                                                  // (Key,Value) = (element, elementIsUnvisitedOrNot)   
	unordered_map<int,int>  hI;                                                  // (Key,Value) = (element, index) 
	
	
	for(int i=0; i<n; i++)                                                
	{  h[arr[i]] = true;                                                         // initially all elements are unvisited                      
	   hI[arr[i]] = i;  }                               
	                                                                                                   
	rangeL = 0;
	
	for(int i=0,curr;  i<n;  i++)                                                // (curr = current number)
	{  if(h[arr[i]]==true)
	   {  
		  range = 0;                                               
	       
	      for(curr=arr[i];  h.count(curr)>0 && h[curr]==1;  curr++,range++)      // including consective numbers of arr[i] when (curr > arr[i])
	      h[curr] = 0; 
	      for(curr=arr[i]-1;  h.count(curr)>0 && h[curr]==1;  curr--,range++)    // including consective numbers of arr[i] when (curr < arr[i])
	      h[curr] = 0; 
	      
	      start = curr+1; 
	      
	      if(range>rangeL || (range==rangeL && hI[start]<hI[startL]))
	      {   rangeL = range;
	          startL = start;	}  
       }
	}                                                      
	                                 
	for(int i=0; i<rangeL; i++,startL++)
	r.push_back(startL);
	return r;
}


int main()
{
	int n;                                                             
	cout<<"Enter size of array: ";                     
	cin>>n;
	
	int *arr = new int[n];
	cout<<"Enter array elements: "; 
	for(int i=0; i<n; i++)                                                       // input array 
	cin>>arr[i];
	 
	cout<<"\n\n\nLongest subsequence of consecutive numbers (in input array) is: ";
	vector<int> vtr = longestSubsequenceOfConsecutiveNumbers(arr,n);
	for(int i=0; i<vtr.size(); i++)
	cout<<vtr[i]<<" ";
	cout<<endl<<endl;
}
 
 
 
/*

  10    1 4 -9 5 9 0 2 6 7 0 
  
*/

 














 
