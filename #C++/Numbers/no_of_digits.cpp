#include <bits/stdc++.h>
using namespace std;

int noOfDigits(int n)
{
	int c=0; 
	
	while(n!=0)
	{
	   c++;
	   n /= 10;	 
	}
	
    return c;	
}
 
int main()
{
    int n=437535;
    
    cout<<noOfDigits(n); 
}









