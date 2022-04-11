#include <bits/stdc++.h>
using namespace std;


template <typename T>
class QueueUsingArray                               // implementing queue using array & template                              
{  
   T *data;
   int firstIndex;
   int nextIndex;
   int size;
   int capacity;
   
     public:
   QueueUsingArray(int n)
   {  data = new T[n];
      firstIndex = -1;
      nextIndex = 0;
      size = 0;
	  capacity = n;  }	
	
   int getSize()
   {  return size;  }
   
   bool isEmpty()
   {  return  (size==0);  }
   	                                                     
   void enqueue(T x)                                // push
   {  if(size==capacity)
   	  {  T *arr = new T[2*capacity];                // double queue capacity when queue is full
   	     int i=0;
   	     for(int j=firstIndex; j<capacity; i++,j++)
   	     arr[i] = data[j];
   	     for(int j=0; j<firstIndex; i++,j++)
   	     arr[i] = data[j];
   	     
   	     firstIndex = 0;
   	     nextIndex = capacity;
   	     capacity *= 2;  
		 delete []data;
		 data = arr;  }
   	  else if(size < capacity)
   	  {  if(firstIndex==-1)
   	     firstIndex = 0;
   	  
   	     data[nextIndex] = x;    
	     nextIndex++;       
   	     nextIndex = nextIndex % capacity;          // if (size < capacity) && (nextIndex == capacity) then go at indexes 0,1,2....
		 
   	     size++;   }        }
	
   T dequeue()                                      // pop
   {  if(size==0)
   	  {  cout<<"Queue is empty"<<endl;
   	     return 0;  }
   	  else if(size > 0)
   	  {  T r = data[firstIndex];
   	  
   	     firstIndex++;
   	     firstIndex = firstIndex % capacity;        // if (size > 0) && (firstIndex == capacity) then go at indexes 0,1,2....
   	 
	     size--;
   	     if(size==0)
   	     {  firstIndex = -1;
	    	nextIndex = 0;  } 
   	     return r;    }	          }
	
   T front()
   {  if(isEmpty())
      {  cout<<"Queue is empty"<<endl;
         return 0;  }
	   
   	  return data[firstIndex];   }	 
};

 
int main()
{
   QueueUsingArray<int> q(5);                       // queue (FIFO data structure)
   
   for(int i=1; i<6; i++)
   q.enqueue(100+i); 
   
   cout<<q.front()<<endl;
   for(int i=1; i<4; i++)
   cout<<q.dequeue()<<" ";
    
   cout<<endl<<q.getSize()<<endl;
   cout<<(q.isEmpty() ? "Queue is empty" : "Queue is not empty")<<endl; 
}























