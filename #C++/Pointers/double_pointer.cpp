#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{ 
	int i = 10;
	
	int *p = &i;
	
	int **dp = &p;                                  // double pointer        
	
	
	(*p)++;     (**dp)++;
	
	
    cout << i <<"  "<< *p <<"  "<< **dp << endl;
    
    cout << &i <<"  "<< p <<"  "<< *dp << endl;
	
    cout << &p <<"  "<< dp << endl;
}
    














