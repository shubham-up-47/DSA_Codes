#include <bits/stdc++.h>
using namespace std;


template <typename T>                          // single template

class Pair                                     // genric class (class made using templates) 
{
   T x;
   T y;
   
     public:
   void setX(T x)
   {  this->x = x;  }
   
   T getX()
   {  return x;  }	
	
   void setY(T y)
   {  this->y = y;  }
   
   T getY()
   {  return y;  }	
};


int main()
{
   Pair<int> p1;                               // using single template
   p1.setX(10);
   p1.setY(20); 
   cout<<p1.getX()<<"  "<<p1.getY()<<endl;
   
   Pair<double> p2;                       
   p2.setX(100.45);
   p2.setY(34.21); 
   cout<<p2.getX()<<"  "<<p2.getY()<<endl; 
 
   Pair<char> p3;  
}



















