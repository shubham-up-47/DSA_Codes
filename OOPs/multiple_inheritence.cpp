#include <bits/stdc++.h>
using namespace std;


class Teacher
{ 
	 public:
   string name;
   string age;
   
   void printA()
   {  cout<<"Teacher: "<<name<<endl;  }
};

class Student
{
     public:
   string name;
   
   void printA()
   {  cout<<"Student: "<<name<<endl;  }
   void print()
   {  cout<<"Student"<<endl;  }
};

class TA: public Teacher, public Student                   // multiple inheritence            
{
     public: 
   void print()
   {  cout<<"TA"<<endl;  }
};

int main()
{
   TA t;
   
   t.age = 21;                                             // age variable is present in only one class, so no need to specify the classs
   t.Student::name = "abc";                                // name variable is present in both classes, so specify the class
   t.Teacher::name = "xyz";
   t.Student::printA();
   t.Teacher::printA();
   
   t.print();                                              // first priority of data/function of TA class (child class)         
}




