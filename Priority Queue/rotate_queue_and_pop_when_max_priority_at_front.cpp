#include <bits/stdc++.h>
using namespace std;

 // a queue (of array elements) is keep rotated, when first element is max it is removed, find count of removed elements when arr[k] is removed

int rotateQueue_and_popWhenLargestElementsAtFront(int *arr, int n, int k)
{
	int count = 0;
	queue<int> q;                         // storing array indexes (queue)                            
	priority_queue<int> p;                // storing array elements priority wise (priority queue)                        
	
	for(int i=0; i<n; i++)
	{  q.push(i);
	   p.push(arr[i]);	}
	
	while(p.size() != 0)
	{  
	   while(arr[q.front()] != p.top())
	   {  q.push(q.front());              // rotating
	      q.pop();  }
	      
	   if(q.front()==k)
	   return count;
	   else
	   {  q.pop(); 
	      p.pop();
	      count++;  }
	} 
}

      
int main()
{ 
	int arr[] = {3,5,1,6,4,7,9,8};
	
	cout<<"Count of total removed elements from queue: ";
	cout<<rotateQueue_and_popWhenLargestElementsAtFront(arr, 8, 4)<<endl; 
}









