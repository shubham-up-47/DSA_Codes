#include <bits/stdc++.h>
using namespace std;


class Vehicle
{ 
	 public:
   int colour;
   
   virtual void print()                     // virtual function (now parentPointer storing addressOfChildClass can access childClassFunction)     
   {  cout<<"Vehicle"<<endl;  } 
};
 
class Car: public Vehicle
{
     public:
   int numGears;
    
   void print()
   {  cout<<"Car"<<endl;  } 
};
      

int main()                                   
{
   Vehicle v;                               // or creating dynamic object class as (Vehicle *vp = new Vehicle;)
   v.print();
   
   Vehicle *vp = &v;               
   vp->print();
   
    
   Car c;
   c.print();
   
   Car *cp1 = &c;                           
   cp1->print();
   
   Vehicle *cp2 = &c;                       // now parentPointer storing addressOfChildClass
   cp2->print();                            // run time polymorphism              
}







