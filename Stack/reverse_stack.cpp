#include <bits/stdc++.h>
using namespace std;


void reverseStack(stack<int> &s, stack<int> &sH)
{
	if(s.size() <= 1)
	return;
	                                                                                                               
	
	while(s.size() != 1)              // (remove first (n-1) elements) & (store them in helper stack)                                          
	{  sH.push(s.top());
	   s.pop();  }
	
	int x = s.top();                  // (remove (n)th elements) & (store it in a variable) 
	s.pop(); 
	
	while(sH.size() != 0)             // (remove the (n-1) elements from helper stack) & (store them in main stack again)   
	{  s.push(sH.top());
	   sH.pop();  }
	                                                    
	reverseStack(s,sH);               // reverse the stack (containg (n-1) elements) using recursion
	 
	s.push(x);                        // store (n)th elements at top of reversed stack                                                        
	  
	  
	return;   
}


int main()
{
   stack<int> s,sH;                   // inbuilt stack (LIFO data structure)
      
   for(int i=1; i<6; i++)             
   s.push(100+i);                            
 
   cout<<"Initial stack: ";
   for(int i=1; i<6; i++)            
   {  cout<<s.top()<<" ";                                                
      s.pop();  }   
   cout<<endl<<endl;     
	  
   for(int i=1; i<6; i++)             
   s.push(100+i);      
    
    
   reverseStack(s,sH);                // reversing stack
   
   
   cout<<"Reversed stack: ";    
   for(int i=1; i<6; i++)            
   {  cout<<s.top()<<" ";                                                
      s.pop();  }   
   cout<<endl<<endl;                 
}















