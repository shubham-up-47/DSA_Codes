#include <bits/stdc++.h>
using namespace std;
 
 
void print(int *p)
{   cout<<*p<<endl;   }
 
void incrementPointer(int *p)
{   p = p+1;   }                          // address of (user defined function) is changed

void increment(int *p)
{   (*p)++;   }                           // de-referencing so value of 'i' is changed 

 
int main()
{ 
	int i = 10; 
	int *p = &i;
	 
	print(p);       
	 
    cout << p <<"  ";
	incrementPointer(p);
	cout << p << endl;
    
    cout << *p <<" ";
	increment(p);
	cout << *p << endl;
}
    













 




