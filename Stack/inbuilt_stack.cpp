#include <bits/stdc++.h>
using namespace std;


int main()
{
   stack<int> s;                                                            // inbuilt stack (LIFO data structure)
    
   for(int i=1; i<6; i++)             
   s.push(100+i);                                                           // push

   for(int i=1; i<4; i++)            
   {  cout<<s.top()<<" ";                                                   // top
      s.pop();  }                                                           // pop
        
   cout<<endl<<"Current size of stack: "<<s.size()<<endl;                   // size
   cout<<(s.empty() ? "Stack is empty" : "Stack is not empty")<<endl;       // empty 
}














 

