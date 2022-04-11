#include <bits/stdc++.h>
using namespace std;
                    
 
int heapSortUsingPQ(int *arr, int n)                                // Heap Sort ( Time Complexity: O(nlogn), Space Complexity: O(n) )
{  
	priority_queue<int, vector<int>, greater<int>> p;
 
	for(int i=0; i<n; i++)
	p.push(arr[i]);	                                                // (vector array) of (size=n) is created to store (min priority queue) 
  
    for(int i=0; !p.empty(); i++)
    {  arr[i] = p.top();
	   p.pop();  }
} 
 
void printArray(int *arr, int n)
{
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
} 

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
	arr[j] = temp;
}

void inplaceHeapSort(int *pq, int n)                                // Inplace Heap Sort ( Time Complexity: O(nlogn), Space Complexity: O(1) )
{                                                             
	for(int i=0; i<n; i++)                                          // build maxHeap array in input array         
	{	                                                            // inserting elements in maxHeapArray (left) from InputArray (right)
	    int cI = i;
	
	    while(cI > 0)                                               // Up Heapify Process (travelling child node to root)
		{  int pI = (cI-1)/2;
		
		   if(pq[cI] > pq[pI])
		   {  swap(pq, cI, pI); 
			  cI = pI;  }
		   else
		   break;  }
    }
   	                                                                                                             
	while(n > 1)	                                                // build sorted array in heap array 
	{                                                              
		swap(pq, 0, n-1);                                           // inserting elements in SortedArray (right) from HeapArray (left) 
		n--;
		
		int pI=0, l_cI=2*pI+1, r_cI=2*pI+2; 
		
		while(l_cI < n)                                             // Down Heapify Process (travelling root to child node)                
		{   int mI = pI;
		
		    if(l_cI < n && pq[l_cI] > pq[mI])
        	mI = l_cI;
		    if(r_cI < n && pq[r_cI] > pq[mI])
        	mI = r_cI;
        	
		    if(mI==pI)
        	break;
			else
		    swap(pq, mI, pI);
			                                                                   
			pI = mI;
			l_cI = 2*pI+1;
			r_cI = 2*pI+2;   }
    }  
}


int main()
{  
	int n;
	cout<<"Enter size of array: ";
	cin>>n; 
	
	int *arr1 = new int[n]; 
	int *arr2 = new int[n];
    cout<<"Enter array elements: ";
	for(int i=0; i<n; i++)
	{  cin>>arr1[i];
	   arr2[i] = arr1[i];  }
  
    heapSortUsingPQ(arr1, n);
    cout<<"\n\nElements of array (sorted using Heap Sort): ";
    printArray(arr1, n);

    inplaceHeapSort(arr2, n);
    cout<<"\n\nElements of array (sorted using Inplace Heap Sort): ";
 
    printArray(arr2, n);
    cout<<endl<<endl; 
}


 /*
  
  8   12 6 5 100 1 9 0 14    
  
           100            
           / \ 
          /   \ 
        14     9                        (Max Heap) = (Complete Binary Tree + Heap Order Property), (last level is filled left to right)
        /\     /\
       /  \   /  \
     12    1  5  0       
     /		
	/
   6
   	
  pq[] = {100,14,9,12,1,5,0,6} 	       (Max Priority Queue) = (Lowest Priority First Out), (O(logn)), (Root=Min element), (stored in array)                                   
 
 */
 
 


 








