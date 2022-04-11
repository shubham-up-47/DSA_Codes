#include <bits/stdc++.h>
using namespace std;


template <typename T, typename V>                     // double template

class Pair
{
   T x;
   V y;
   
     public:
   void setX(T x)
   {  this->x = x;  }
   
   T getX()
   {  return x;  }	
	
   void setY(V y)
   {  this->y = y;  }
   
   V getY()
   {  return y;  }	
};


int main()
{
   Pair<int,double> p1;                               // using double template
   p1.setX(10);
   p1.setY(34.21);  
   cout<<p1.getX()<<"  "<<p1.getY()<<endl;
}

















