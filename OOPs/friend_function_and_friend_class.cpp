#include <bits/stdc++.h>
using namespace std;


class Bus 
{
	 public: 
   void print();                           // declaring the function of Bus class which will be friend   
};
     
class Vehicle                              // our class 
{
     private:
   int x;
   
     protected:
   int y;
   
	 public:
   int z;
   
   friend void Bus::print();               // friend function  
   friend void test();                     // friend function  
   friend class Truck;                     // friend class  
};

void Bus::print()                          // defining the function of Bus, which is friend function of Vehicle class  
{
   Vehicle v;
   v.x = 10;
   v.y = 20;
   v.z = 30;
   cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
}

void test()                                // friend function of Vehicle class 
{
   Vehicle v;
   v.x = 10;
   v.y = 20;
   v.z = 30;
   cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
}

class Truck                                // friend class of Vehicle class 
{
     public: 
   void display()
   {  Vehicle v;
      v.x = 10;
      v.y = 20;
      v.z = 30;
      cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;  }
};
 

int main()
{
   Bus b;                                  // friend function  
   b.print();
   
   Truck t;                                // friend class  
   t.display();
   
   test();                                 // friend function  
}










