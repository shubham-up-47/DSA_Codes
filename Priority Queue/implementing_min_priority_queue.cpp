#include <bits/stdc++.h>
using namespace std;

 
class PriorityQueue                                                        // class for creating a Min Priority Queue 
{   
	vector<int> pq;                                                        // storing Min Priority Queue in an vector Array 
	
	   public:
    PriorityQueue()
	{     }	
	
	bool isEmpty()
	{  return (pq.size()==0);  }
	
	int getSize()
	{  return pq.size();  }	
	
	int getMin()
	{  if(isEmpty())
	   return 0;
	   
	   return pq[0];  }
	
	void insert(int x)
	{
		pq.push_back(x);
		int cI = pq.size()-1;
		
		while(cI > 0)                                                      // Up Heapify Process 
		{  int pI = (cI-1)/2;
		
		   if(pq[cI] < pq[pI])
		   {  int temp = pq[cI];
		      pq[cI] = pq[pI];
			  pq[pI] = temp;
			  
			  cI = pI;  }
		   else
		   break;	}
	}
	
	int removeMin()
	{
		if(isEmpty())
		return 0;
		
		int r = pq[0];
		pq[0] = pq[pq.size()-1];
		pq.pop_back();
		
		int pI=0, l_cI=2*pI+1, r_cI=2*pI+2;
		
		while(l_cI < pq.size())                                            // Down Heapify Process                
		{   int mI = pI;
		
		    if(l_cI < pq.size() && pq[l_cI] < pq[mI])
        	mI = l_cI;
		    if(r_cI < pq.size() && pq[r_cI] < pq[mI])
        	mI = r_cI;
		    if(mI==pI)
        	break;
			
		    int temp = pq[mI];
		    pq[mI] = pq[pI];
			pq[pI] = temp;
			  
			pI = mI;
			l_cI = 2*pI+1;
			r_cI = 2*pI+2;   }
		
		return r; 
	} 
};
 

int main()
{ 
	int n;
	cout<<"Enter size of min priority queue: ";
	cin>>n;
 
	PriorityQueue p;

    cout<<"Enter elements: ";
	while(n--)
	{  int x;
	   cin>>x;
	   p.insert(x);	 }
 

    cout<<"\n\nSize of min priority queue: "<<p.getSize()<<endl;
	cout<<"Min element: "<<p.getMin()<<endl;
    cout<<"Elements of min priority queue (in sorted order): ";
    while(!p.isEmpty())
    cout<<p.removeMin()<<" ";
    cout<<endl<<endl; 
}

          
		                                                                                          
 /*
  
  8 12 6 5 100 1 9 0 14    
  
            0            
           / \ 
          /   \ 
         5     1                        (Min Heap) = (Complete Binary Tree + Heap Order Property), (last level is filled left to right)
        /\     /\
       /  \   /  \
     14   12 9    6       
     /		
	/
   100
   	
  pq[] = {0,5,1,14,12,9,6,100} 	       (Min Priority Queue) = (Lowest Priority First Out), (O(logn)), (Root=Min element), (stored in array)                                   
 
 */
 
 
 

 // Min Heap = (parent data < child data)
 
 // (pq=PriorityQueue), (l_cI=leftChildIndex), (r_cI=rightChildIndex), (cI=childIndex), (pI=parentIndex), (mI=minValueChildIndex)   












