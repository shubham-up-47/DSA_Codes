#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Node                                       // node of LL  
{    public:
   T data;
   Node<T> *next;
   
   Node(T data)
   {  this->data = data;
      this->next = NULL;  } 
};

template <typename T>
class StackUsingLL                               // implementing stack using LL & template                               
{    
   Node<T> *head; 
   int size;
   
     public:
   StackUsingLL()
   {  this->head = NULL;
	  this->size = 0;  }	
	
   int getSize()
   {  return size;  }
   
   bool isEmpty()
   {  return  (size==0);  }
   	
   void push(T x)
   {  size++;
   
      Node<T> *np = new Node<T>(x);              // double stack capacity when stack is full
   	  np->next = head;
	  head = np;   }	
	
   T pop()
   {  if(head==NULL)
   	  {  cout<<"Stack is empty"<<endl;
   	     return 0;  }

   	  
   	  Node<T> *temp = head;
   	  T r = head->data;
   	  
   	  head = head->next;
   	  delete temp;
   	  size--;
 
   	  return r;   }	
	
   T top()
   {  if(head==NULL)
      {  cout<<"Stack is empty"<<endl;
         return 0;  }
	   
   	  return head->data;   }	 
};

 
int main()
{
   StackUsingLL<char> s;                         // stack (LIFO data structure)
   
   for(int i=1; i<6; i++)
   s.push(100+i); 
   
   cout<<s.top()<<endl;
   
   for(int i=1; i<4; i++)
   cout<<s.pop()<<" ";
   
   cout<<endl<<s.getSize()<<endl;
   
   cout<<(s.isEmpty() ? "Stack is empty" : "Stack is not empty")<<endl; 
}




















