#include <bits/stdc++.h>
using namespace std;
 
// reference variable = (another name of same memory), (must initialize a reference variable otherwise error)  

int a,b;
                         
int& f1(int n)                              // returning variable by reference (so new memory is not created)
{  a = n;
   return a;  }
                                          
int* f2(int n)                              // returning variable by address (so new memory is not created)
{  b = n;
   return &b;  }
    
void increment(int &i)                      // passing variable by reference (so new memory is not created)
{  i++;  }


int main()
{
   int i = 10;     
   
   
   int &r = i;                              // reference variable
   r++;
   cout << i <<" "<< r << endl;                   
   
   
   increment(i);  
   int &rf = f1(i);  
   int *pf = f2(i);                       
   cout << rf <<" "<< *pf << endl;        
}                                     
                                     
                               
 










