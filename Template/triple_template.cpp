#include <bits/stdc++.h>
using namespace std;


template <typename T, typename V, typename W>                    // double template

class Pair
{
   T x;
   V y;
   W z;
   
     public:
   void setX(T x)
   {  this->x = x;  }
   
   T getX()
   {  return x;  }	
	
   void setY(V y)
   {  this->y = y;  }
   
   V getY()
   {  return y;  }	
   
   void setZ(W z)
   {  this->z = z;  }
   
   W getZ()
   {  return z;  }	
};


int main()
{
   Pair<int,double,string> p1;                                   // using double template
   p1.setX(10);
   p1.setY(34.21);  
   p1.setZ("nitt");
   cout<<p1.getX()<<"  "<<p1.getY()<<"  "<<p1.getZ()<<endl;
}






















