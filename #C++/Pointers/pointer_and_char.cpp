#include <bits/stdc++.h>
using namespace std;
 
 // size of all pointer (int*, char*, double*...) is same bcz we store only address in it                             

int main()
{  
	char b[] = "abc";                                        // (char array of size 4) is created where last char is NULL
	char *p = &b[0];
	
	cout<<b<<"  "<<p<<"  "<<&b[0]<<"  "<<&b[1]<<endl;        // it will keep printing till it finds a NULL char  
	  
	cout<<b[0]<<"  "<<b[1]<<"  "<<b[2]<<endl;                // each will print a char 
	
	
	
	char c = 'a';
	char *cp = &c;
	cout << cp << endl;                                      // it will keep printing till it finds a NULL char 
	
	char s[] = "abcde";                                      // (char array of size 6) is created 
	char *sp = "abcde";                                      // pointer points to (temporary char array of size 6) created   
}










 




