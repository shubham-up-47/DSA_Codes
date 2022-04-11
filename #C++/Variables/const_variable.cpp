#include <bits/stdc++.h>
using namespace std;
 
// const variable = (variable whose value can't be changed), (must initialize a const variable otherwise error)
// const reference variable = (variable whose reference variable can't be changed) 
// const pointer variable = (variable whose address variable can't be changed)                    

int main()
{
   const int x1 = 10;                           // const variable  
   const int &r1 = x1;                          // reference of (const variable) can be stored in (const reference variable)                    
   const int *p1 = &x1;                         // address of (const variable) can be stored in (const pointer) 
               
                
   int x2 = 25;
   const int &r2 = x2;                          // const reference variable                                             
               
                   
   int x3 = 41;                      
   const int *p3 = &x3;                         // const pointer variable 
                               
                      
   cout << x1 << " " << r1 << endl;
   cout << x2 << " " << r2 << endl;
   cout << x3 << " " << *p3 << endl;                     
}                                     
                                     
                               
 
 
 
 
 
 
 
