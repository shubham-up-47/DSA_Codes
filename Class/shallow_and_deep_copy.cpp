#include <bits/stdc++.h>
using namespace std;
 
 
// Shallow Copy = (copying addressOfMemory where data is stored), (by Default_CopyConstructor & Default_CopyAssignmentOperator) 
// Deep Copy = (copying dataOneByOne in new array/variable), (by UserDefined_CopyConstructor & UserDefined_CopyAssignmentOperator)  
 
 
class Student
{     public:
	int age;                     
	int rollNumber;           
	            
	Student()                                    // default constructor
	{  age = 0;
	   rollNumber = 0;  }   
			                             
	Student(int a, int r)                        // parametrized constructor
	{  age = a;
	   rollNumber = r;  }   
	                                                   
    void display()                                 
    {  cout<<age<<" "<<rollNumber<<" "<<endl;  } 
};
 
 
class Teacher
{     public:
	int age;                     
	int salary;         
	
	Teacher()                                    // default constructor
	{  age = 0;
	   salary = 0;  }     
	 
	Teacher(int a, int s)                        // parametrized constructor
	{  age = a;
	   salary = s;  }   
	   
	Teacher(Teacher const &t)                    // UserDefined_CopyConstructor (deep copy)  
	{  age = t.age;
	   salary = t.salary;  }   
	                                    
	void operator=(Teacher const &t)             // UserDefined_CopyAssignmentOperator (deep copy)  
	{  age = t.age;
	   salary = t.salary;  }   
		                                               
    void display()                                 
    {  cout<<age<<" "<<salary<<" "<<endl;  } 
};

 
int main()
{
   Student s(10,1001);                           // static object
   Student *sp = new Student(10,1001);           // dynamic object             
  
  
   Student s1(s);                                // Default_CopyConstructor
   s1.display(); 
   Student s2 = s;                               // Default_CopyConstructor
   s2.display();
    
   
   Student s3;
   s3 = s;                                       // Default_CopyAssignmentOperator            
   s3.display();
    
   
   
   cout<<endl<<endl;
   
   
    
   Teacher t(10,1050);                           // static object
   Teacher *tp = new Teacher(10,1050);           // dynamic object             
 
   
   Teacher t1(t);                                // UserDefined_CopyConstructor
   t1.display(); 
   Teacher t2 = t;                               // UserDefined_CopyConstructor
   t2.display();
    
   
   Teacher t3;
   t3 = t;                                       // UserDefined_CopyAssignmentOperator                             
   t3.display(); 
}


 






