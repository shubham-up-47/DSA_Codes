#include <bits/stdc++.h>
using namespace std;

// UDF = user defined function
// UDF with inline = (UDF code is copied & comes to place where function call is done), (fast execution), (valid for small UDF only)                                          

inline int maxE(int a, int b)  // UserDefinedFunction with inline                                                
{   return (a>b) ? a : b;   }


int main()
{ 
	int x=INT_MIN, arr[] = {4,1,0,7,3,2};
	
	for(int i=0; i<6; i++)
	x = maxE(x, arr[i]);
	
	cout << x << endl;
}





















