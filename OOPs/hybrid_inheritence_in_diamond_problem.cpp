#include <bits/stdc++.h>
using namespace std;


class Vehicle
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
   
   void print()
   {  cout<<"Vehicle"<<endl;  } 
};

class Truck: virtual public Vehicle              // hierarchial inheritence using virtual keyword                       
{
     public: 
   Truck() 
   {  cout<<"Truck's Default Constructor"<<endl;  }
  ~Truck()
   {  cout<<"Truck's Distructor"<<endl;  } 
};

class Car: virtual public Vehicle                // hierarchial inheritence using virtual keyword   
{
     public:
   int numGears;
   
   Car() 
   {  cout<<"Car's Default Constructor"<<endl;  }
   Car(int x,int y) : Vehicle(y)
   {  numGears = x;
      cout<<"Car's Parametrized Constructor"<<endl;  }
  ~Car()
   {  cout<<"Car's Distructor"<<endl;  } 
   
   void print()
   {  cout<<"Car"<<endl;  } 
};

class Bus : public Car, public Truck             // multiple inheritence         
{
	 public:
   Bus() : Vehicle(5)                            // hybrid inheritence (initializing Vehicle property)               
   {  cout<<"Bus's Default Constructor"<<endl;  } 
  ~Bus()
   {  cout<<"Bus's Distructor"<<endl;  } 
   
   void print()
   {  cout<<"Bus"<<endl;  }  
};
        

int main()
{
   Bus b;                                               
   
   cout<<endl<<endl;
   
   b.print(); 
   b.Car::print();                               // if print() is present in current class then it will print, otherwise it will go to parent class
   b.Truck::print();
   b.Vehicle::print();
   
   cout<<endl<<endl;
}










