#include <bits/stdc++.h>
using namespace std;

template <typename T>
class StackUsingArray                                  // implementing stack using array & template                              
{  
   T *data;
   int nextIndex;
   int capacity;
   
     public:
   StackUsingArray()
   {  data = new T[4];
      nextIndex = 0;
	  capacity = 4;  }	
	
   int size()
   {  return nextIndex;  }
   
   bool isEmpty()
   {  return  (nextIndex==0);  }
   	
   void push(T x)
   {  if(nextIndex==capacity)
   	  {  T *arr = new T[2*capacity];                   // double stack capacity when stack is full
   	     for(int i=0; i<capacity; i++)
   	     arr[i] = data[i];
   	     
   	     capacity *= 2;  
		 delete []data;
		 data = arr;  }
   	  
   	  data[nextIndex] = x;
   	  nextIndex++;   }	
	
   T pop()
   {  if(isEmpty())
   	  {  cout<<"Stack is empty"<<endl;
   	     return 0;  }
   	
   	  nextIndex--;
   	  return data[nextIndex];   }	
	
   T top()
   {  if(isEmpty())
      {  cout<<"Stack is empty"<<endl;
         return 0;  }
	   
   	  return data[nextIndex-1];   }	 
};

 
int main()
{
   StackUsingArray<int> s;                             // stack (LIFO data structure)
   
   for(int i=1; i<6; i++)
   s.push(100+i); 
   cout<<s.top()<<endl;
   for(int i=1; i<4; i++)
   cout<<s.pop()<<" ";
   cout<<endl<<s.size()<<endl;
   cout<<(s.isEmpty() ? "Stack is empty" : "Stack is not empty")<<endl; 
}









 



 



