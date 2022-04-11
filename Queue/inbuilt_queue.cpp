#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
   queue<int> q;                                                            // inbuilt queue (FIFO data structure)
   
   for(int i=1; i<6; i++)
   q.push(100+i);                                                           // push
   
   
   for(int i=1; i<6; i++)
   {  cout<<q.front()<<" ";                                                 // front
      q.pop();   }                                                          // pop
      
   cout<<endl<<q.size()<<endl;                                              // size  
   cout<<(q.empty() ? "Queue is empty" : "Queue is not empty")<<endl;       // empty
}









 





