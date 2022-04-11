#include <bits/stdc++.h>
using namespace std;

  // printing Resultant Median each time, while taking array elements one by one (left to right)

void  printMedianEachTime_whileTakingArrayElements(int *arr, int n)     
{
	int currM = 0;                                                    // current median
	priority_queue<int>  maxHeap;
	priority_queue<int, vector<int>, greater<int>>  minHeap;
	 
	for(int i=0; i<n; i++)
	{
	    if(maxHeap.size() > minHeap.size())
	    {   if(arr[i] < currM)
	   	    {   minHeap.push(maxHeap.top());
	   	        maxHeap.pop();
	   	        maxHeap.push(arr[i]);   }
	   	   	else
	   	   	minHeap.push(arr[i]);
	   	   	
	   	   	currM = (maxHeap.top() + minHeap.top())/2;	  }
	    
		else if(maxHeap.size() == minHeap.size())
	    {   if(arr[i] < currM)
	   	    {   maxHeap.push(arr[i]);
				currM = maxHeap.top();   }
	   	   	else
	   	   	{   minHeap.push(arr[i]);
		    	currM = minHeap.top();   }    }
	           	    	
		else
	    {   if(arr[i] > currM)
	   	    {   maxHeap.push(minHeap.top());
	   	        minHeap.pop();
	   	        minHeap.push(arr[i]);   }
	   	   	else
	   	   	maxHeap.push(arr[i]);
	   	   	
	   	   	currM = (maxHeap.top() + minHeap.top())/2;	  }
			
		cout<<currM<<" ";
	} 
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
  
    cout<<"\n\n\n'Medians of resultant array' while taking elements of input array one by one: ";
    printMedianEachTime_whileTakingArrayElements(arr, n); 
    cout<<endl<<endl; 
}


/*
  
  8 12 6 5 100 1 9 0 14   
   
*/         
        

// Median of even sized array: average of (middle most elements of sorted array)
// Median of odd sized array: (middle most element of sorted array)










