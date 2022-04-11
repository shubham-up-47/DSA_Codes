#include <bits/stdc++.h>
using namespace std;
 
  
void printArray(int *arr, int n)
{   
    for(int i=0; i<n; i++)
    cout << *(arr+i) << "  ";
    cout << endl;   
}
  
  
int main()
{ 
	int a[]={2,4,5,1,7}, n=5;                                 // there is no memory for a, so sizeof(a) = arraySize
	int *p = a;
	 
	printArray(a,n);
	cout << a << endl;
	cout << sizeof(a) << "  " << sizeof(p) << endl;           // arraySize &  pointerSize     (intSize = 4 Byte)
    cout << sizeof(a)/sizeof(a[0]) << endl;                   // array length            
}
    












