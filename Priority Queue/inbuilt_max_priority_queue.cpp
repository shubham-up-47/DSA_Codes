#include <bits/stdc++.h>
using namespace std;

 
int main()
{ 
	int n;
	cout<<"Enter size of max priority queue: ";
	cin>>n;
 
	priority_queue<int> p;

    cout<<"Enter elements: ";
	while(n--)
	{  int x;
	   cin>>x;
	   p.push(x);	 }


    cout<<"\n\nSize of max priority queue: "<<p.size()<<endl;
	cout<<"Max element: "<<p.top()<<endl;
    cout<<"Elements of max priority queue (in sorted order): ";
    while(!p.empty())
    {  cout<<p.top()<<" ";
	   p.pop();  }
    cout<<endl<<endl; 
}

	                                                                                          
 /*
  
  8 12 6 5 100 1 9 0 14    
         
           100            
           / \ 
          /   \ 
        14     12     (Max Heap) = (Complete Binary Tree + Heap Order Property), (last level is filled left to right), (parent data > child data)
        /\     /\
       /  \   /  \
      9    6 5    1       
     /		
	/
   0
   		 	 
  pq[] = {100,14,9,12,1,5,0,6}    (Max Priority Queue) = (Highest Priority First Out), (O(logn)), (Root=Max element), (stored in array)                                           
 
 */
 
 
 




