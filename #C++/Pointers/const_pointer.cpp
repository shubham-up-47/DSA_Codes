#include <bits/stdc++.h>
using namespace std;
 

void g(const int &r)                            // now g cant do any changes to i bcz (const reference variable) 
{  cout << r << endl;  }             

void f(const int *p)                            // now f cant do any changes to i bcz (const pointer) 
{  cout << *p << endl;	}    


int main()
{ 
   int i = 13;
   int &r = i; 
   int *p = &i;
   
   g(r);
   f(p);
}                                     
                                     
             
















