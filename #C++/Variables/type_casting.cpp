#include<iostream>
using namespace std;


int main()
{ 
  char x = 'p';
  int a = x;                                  // implicid typecasting 
  
  float i = 3.4; 
  int b = i;                                  // implicid typecasting               

  char y = (char)(x + b);	                  // explicid typecasting 
  
  int *ip = &b;
  char *cp = (char*)ip;                       // explicid typecasting 
	  
  cout<<" a = "<<a<<endl;
  cout<<" b = "<<b<<endl;
  cout<<" y = "<<y<<endl;	
  cout<<"*cp = "<<*cp<<endl;
}



















