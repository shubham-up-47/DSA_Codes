#include <bits/stdc++.h>
using namespace std;
 
void reverseQueue(queue<int> &q)
{
   if(q.size()==0 || q.size()==1)
   return;
   
   
   int x = q.front();
   q.pop();	
   
   reverseQueue(q);
   q.push(x);	
	
   
   return;	
} 
 
int main()
{
   queue<int> q;                          // inbuilt queue (FIFO data structure)
   
   
   cout<<"Queue before reversing: ";
   for(int i=1; i<9; i++)
   {  q.push(100+i);                      // push
      cout<<100+i<<" ";  } 
   cout<<endl;   
      
      
   reverseQueue(q);                       // reversing the queue
   
   
   cout<<"\nQueue after reversing: ";
   for(int i=1; i<9; i++)
   {  cout<<q.front()<<" ";               // front
      q.pop();   }                        // pop 
   cout<<endl;  
}








