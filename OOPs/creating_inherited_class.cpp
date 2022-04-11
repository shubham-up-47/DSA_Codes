#include <bits/stdc++.h>
using namespace std;


class Vehicle                             // base class
{
     private:
   int x;
     protected:
   int y;
	 public:
   int z;
};

class Car: public Vehicle                 // derrived class [(y,z) are inherited as (protected,public)]                    
{
     public:                              // accessible everywhere
   int p;
     private:                             // accessible inside        
   int q = 13;
	 protected:                           // accessible inside & in derrived class            
   int r = 25;
   
     public:
   void print()
   {  y = 37;
      cout<<y<<" "<<z<<endl;
      cout<<p<<" "<<q<<" "<<r<<endl;  }
};


int main()
{
   Vehicle v;                           
   v.z = 41;
   
   Car c;
   c.z = 52;
   c.p = 69;
   c.print();
}








