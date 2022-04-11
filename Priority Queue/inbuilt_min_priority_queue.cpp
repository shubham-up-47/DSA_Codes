#include <bits/stdc++.h>
using namespace std;

 
int main()
{ 
	int n;
	cout<<"Enter size of min priority queue: ";
	cin>>n;
 
	priority_queue<int, vector<int>, greater<int>> p;

    cout<<"Enter elements: ";
	while(n--)
	{  int x;
	   cin>>x;
	   p.push(x);	 }
 

    cout<<"\n\nSize of min priority queue: "<<p.size()<<endl;
	cout<<"Min element: "<<p.top()<<endl;
    cout<<"Elements of min priority queue (in sorted order): ";
    while(!p.empty())
    {  cout<<p.top()<<" ";
	   p.pop();  }
    cout<<endl<<endl; 
}

          
		                                                                                          
 /*
  
  8 12 6 5 100 1 9 0 14    
  
            0            
           / \ 
          /   \ 
         5     1      (Min Heap) = (Complete Binary Tree + Heap Order Property), (last level is filled left to right), (parent data < child data)
        /\     /\
       /  \   /  \
     100  12 9    6       
     /		
	/
   14
   	
  pq[] = {0,5,1,14,12,9,6,100} 	  (Min Priority Queue) = (Lowest Priority First Out), (O(logn)), (Root=Min element), (stored in array)                                   
 
 */
 
 
  








