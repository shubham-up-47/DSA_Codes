#include <bits/stdc++.h>
using namespace std;
 
   // K Sorting can be done on some special arrays
 
void kSort(int *arr, int k, int n)                       // K Sort ( Time Complexity: O(nlogk), Space Complexity: O(k) )      
{  
	priority_queue<int, vector<int>, greater<int>> p;                           
	
	for(int i=0; i<k; i++)                              // storing first K elements of Array in PriorityQueue
	p.push(arr[i]);	                                               
  
  
    int i=0;                                            // generate SortedArray by maintaining K size PriorityQueue
    
    for(int j=k; j<n; i++,j++)                                  
    {  arr[i] = p.top();                               
	   p.pop();                                         // remove minElement from PriorityQueue, then insert nextElement from Array       
	   p.push(arr[j]);  }
	   
	for(int j=0; j<k; i++,j++)                          // lastly remove left K elements from PriorityQueue 
	{  arr[i] = p.top();
       p.pop();	 }
} 
          
void printArray(int *arr, int n)
{
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
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
	cout<<"Enter K: ";
	cin>>k; 
   
    kSort(arr, k, n);
    cout<<"\n\nElements of array (sorted using K Sort): ";
    printArray(arr, n); 
    cout<<endl<<endl; 
}



/*

 5 9 4 7 15 12 3   (n=5, k=3)

 
    Index no                              0                1                2                3                4      
Input array elements              [       9      ] [       4      ] [       7      ] [       15     ] [       12      ]

 
Indexes to be searched to get     [    (0,1,2)   ] [  (0,1,2,3)   ] [ (0,1,2,3,4)  ] [   (1,2,3,4)  ] [    (2,3,4)    ]
   Sorted array elements 
 
*/



 // Indexes to be searched to get (i)th index Sorted array element are { i-(k-1), i-(k-2),.....i-(1), i, i+(1),.....i+(k-2), i+(k-1) }
 
 
 
 
  










