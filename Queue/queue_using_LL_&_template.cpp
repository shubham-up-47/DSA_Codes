#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Node                                    // node of LL  
{    public:
   T data;
   Node<T> *next;
   
   Node(T data)
   {  this->data = data;
      this->next = NULL;  } 
};


template <typename T>
class QueueUsingLL                            // implementing queue using LL & template                               
{    
   Node<T> *head; 
   Node<T> *tail; 
   int size;
                                    
     public:
   QueueUsingLL()
   {  this->head = NULL;
      this->tail = NULL;
	  this->size = 0;  }	
	
   int getSize()
   {  return size;  }
   
   bool isEmpty()
   {  return  (size==0);  }
   	                                         
   void enqueue(T x)                          // push
   {  size++; 
      Node<T> *np = new Node<T>(x);            
   
   	  if(head==NULL)
   	  {  head = np;
   	     tail = np;  }
	  else
	  {  tail->next = np;
	  	 tail = np;  }    }	
	
   T dequeue()                                // pop
   {  if(head==NULL)
   	  {  cout<<"Queue is empty"<<endl;
   	     return 0;  }
  
   	  Node<T> *temp = head;
   	  T r = head->data;
   	  
   	  head = head->next;
   	  delete temp;
   	  size--;
 
   	  return r;   }	
	
   T front()
   {  if(head==NULL)
      {  cout<<"Stack is empty"<<endl;
         return 0;  }
	   
   	  return head->data;    }	 
};

  
int main()
{
   QueueUsingLL<int> q;                       // queue (FIFO data structure)
   
   for(int i=1; i<6; i++)
   q.enqueue(100+i); 
   
   cout<<q.front()<<endl;
   for(int i=1; i<4; i++)
   cout<<q.dequeue()<<" ";
    
   cout<<endl<<q.getSize()<<endl;
   cout<<(q.isEmpty() ? "Queue is empty" : "Queue is not empty")<<endl; 
}













