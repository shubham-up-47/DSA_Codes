#include <bits/stdc++.h>
using namespace std;
 
 
int* findFirst_K_SmallestElements(int *arr, int k, int n)        // highly optimized solution { O(nlogk) }                        
{  
	priority_queue<int> p; 
                            
	for(int i=0; i<k; i++)                                       // storing first K elements of Array in MaxPriorityQueue
	p.push(arr[i]);	                    
    
    for(int i=k; i<n; i++)           // travel on array & maintain (K size PriorityQueue) which contains (K smallest elements from visited array)                       
    {  if(arr[i] < p.top())                               
	   {  p.pop();                                                
	      p.push(arr[i]);  }  }
	   
	   
	   
	int *brr = new int[k];
	
	for(int i=0; i<k; i++)                                       // remove K smallest elements from PriorityQueue & store in array                                     
	{  brr[i] = p.top();
       p.pop();	 }
       
    return brr;
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
   
    int *brr = findFirst_K_SmallestElements(arr, k, n);
    cout<<"\n\nFirst K smallest elements of input array are: ";
    printArray(brr, k); 
    cout<<endl<<endl; 
}
 

/*

 5 9 4 7 15 12 3   (n=5, k=3) 
 
*/

 
 
 






  

