#include <bits/stdc++.h>
using namespace std;
                                                                                                                                                           
// Dequeue (double ended queue): In this queue, elements can be inserted & deleted from both the ends

template <typename T>
class DequeueUsingArray             // implementing dequeue using array & template                              
{  
   T *data;
   int front;
   int rear;
   int size;
   int capacity;
                                                                                                         
     public:
   DequeueUsingArray(int n)
   {  data = new T[n];
      front = -1;
      rear = -1;
      size = 0;
	  capacity = n;  }	
	
   int getSize()
   {  return size;  }
   
   bool isEmpty()
   {  return  (size==0);  }
   	                                                     
   void insertFront(T x)                       
   {  if(size==0)
      {  front = 0;
         rear = 0;
         
         size++;
         data[front] = x;  }
   	  else if(size < capacity)
   	  {  if(front==0)               // while insertFront, if (size < capacity) && (front == 0) then go at indexes (n-1),(n-2),(n-3)......
   	     front = capacity-1;
   	     else
   	     front--;
   	  
   	     size++; 
   	     data[front] = x;   }  
      else if(size==capacity)
   	  {  cout<<"Dequeue is full"<<endl;  }    }
	                                                                                                                                                                                                   
   void insertRear(T x)                      
   {  if(size==0)
      {  front = 0;
         rear = 0;
         size++;
         data[rear] = x;  }
   	  else if(size < capacity)
   	  {  rear++;
   	     rear = rear % capacity;    // while insertRear, if (size < capacity) && (rear == capacity) then go at indexes 0,1,2....
   	    
   	     size++; 
   	     data[rear] = x;   }  
      else if(size==capacity)
   	  {  cout<<"Dequeue is full"<<endl;  }    }
	                                                               
   void deleteFront()                         
   {  if(size==0)
   	  {  cout<<"Dequeue is empty"<<endl;  }
   	  else if(size==1)
      {  front = -1;
         rear = -1;
         size--;  }     
	  else if(size > 1)	 
   	  {  front++;
   	     front = front % capacity;  // while deleteFront, if (size > 1) && (rear == capacity) then go at indexes 0,1,2....
   	     
	     size--;  }    }
	                                                                                                                                                           
   void deleteRear()                       
   {  if(size==0)
   	  {  cout<<"Dequeue is empty"<<endl;  }
   	  else if(size==1)
      {  front = -1;
         rear = -1;
         size--;  }     
	  else if(size > 1)	 
	  {  if(rear==0)                // while deleteRear, if (size > 1) && (rear == 0) then go at indexes (n-1),(n-2),(n-3)......
	     rear = capacity-1;
         else
	     rear--;    
	                                                                                                             
	     size--;   }    }
	
   T getFront()
   {  if(isEmpty())
      {  cout<<"Dequeue is empty"<<endl;
         return 0;  }
	   
   	  return data[front];   }	 
   	  
   T getRear()
   {  if(isEmpty())
      {  cout<<"Dequeue is empty"<<endl;
         return 0;  }
	   
   	  return data[rear];   }	 
};

 
int main()
{
   DequeueUsingArray<int> q(6);     // Dequeue (size=6)
   
   for(int i=1; i<5; i++)           // inserting (8) elements
   {  q.insertFront(100+i); 
      q.insertRear(100+i);   }
   
   for(int i=1; i<4; i++)           // printing & removing             
   {  cout<<q.getFront()<<endl;
      cout<<q.getRear()<<endl;

      q.deleteFront();
      q.deleteRear();   }
    
   cout<<"Dequeue current size: "<<q.getSize()<<endl;  
   cout<<(q.isEmpty() ? "Dequeue is empty" : "Dequeue is not empty")<<endl; 
}














 




