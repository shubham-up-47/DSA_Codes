#include <bits/stdc++.h>
using namespace std;


class Vehicle                                         // abstract class          
{ 
	 public:
   int colour;
   
   virtual void print() = 0;                          // pure virtual function           
};

class Car: public Vehicle
{
     public:
   int numGears;
    
   void print()                                       // function with defination        
   {  cout<<"Car"<<endl;  } 
};
   

int main()                                            // (Vehicle v;) will give error bcz abstract class     
{
   Car c; 
   c.print(); 
}











