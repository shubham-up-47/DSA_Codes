#include <bits/stdc++.h>
using namespace std;
                                                             
                                                                        
class Student
{      public:
	int age;   
	static int classNo;                                   // static variable/property (variable whose value is initialized outside the class)                                                                                                                                                  
	const int rollNo;                                     // const variable/property (variable whose value can't be changed)                                                                                                              
	int &x;                                               // reference variable/property (alternate name of already existing variable)
             	                                                                                                                                 
    Student() : rollNo(100), x(age)                      
    {     }   
			                             
	Student(int r) : rollNo(r), x(age)                    // initialisation list (mainly used to initialize const/reference variable)                                                                      
	{     }   
	   
	Student(int r, int a) : rollNo(r), age(a), x(age)                                 
	{     }                                                  
	                                                                                                              
    void display()                                 
    {  cout<<classNo<<"  "<<rollNo<<endl;  } 
    
    int getAge() const                                    // const function (function which doesn't change any property of object)               
    {  return age;  }	
    
    static int getClassNo()                               // static function (function from which we try to access static variable) 
    {  return classNo;  }
};
                                                                   
                
int Student::classNo = 8;                                 // initialisating static variable/property                      
  
  
int main()
{
   Student s1;    
   s1.display(); 
   
   Student s2(108);                       
   s2.display();
      
   Student s3(112,14);                                          
   s3.display(); 
   cout<<s3.getAge()<<"  "<<s3.getClassNo()<<endl;
}


 




 
 
 
 
 
 
  
