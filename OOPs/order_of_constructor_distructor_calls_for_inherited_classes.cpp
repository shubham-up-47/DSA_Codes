#include <bits/stdc++.h>
using namespace std;


class Vehicle                                                     // base class
{
     private:
   int maxSpeed;
   
     protected:
   int numTyres;
   
	 public:
   int colour;
   
   Vehicle()
   {  cout<<"Vehicle's Default Constructor"<<endl;  }
   Vehicle(int x)
   {  maxSpeed = x;
      cout<<"Vehicle's Parametrized Constructor"<<endl;  }
  ~Vehicle()
   {  cout<<"Vehicle's Distructor"<<endl;  } 
};

class Bike: public Vehicle
{
     public:
   int numChain;
   
   Bike(int x) : Vehicle()
   {  numChain = x;
      cout<<"Bike's Parametrized Constructor"<<endl;  }
  ~Bike()
   {  cout<<"Bike's Distructor"<<endl;  } 
};

class Car: public Vehicle                                      
{
     public:
   int numGears;
   
   Car(int x,int y) : Vehicle(y)                                  // parametrized constructor & inheritence               
   {  numGears = x;
      cout<<"Car's Parametrized Constructor"<<endl;  }
  ~Car()
   {  cout<<"Car's Distructor"<<endl;  } 
};

class Alto : public Car                                                               
{
	 public:
   Alto(int x,int y) : Car(x,y)
   {  cout<<"Alto's Parametrized Constructor"<<endl;  } 
  ~Alto()
   {  cout<<"Alto's Distructor"<<endl;  }  
};
        

int main()
{
   Bike b(2);
   cout<<endl<<endl;
   
   Alto a(4,5);
   cout<<endl<<endl;
}















