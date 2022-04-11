#include <bits/stdc++.h>
using namespace std;

int noOfZeros(int n)
{
	if(n==0)
	return 1;
	else if(n < 10)
	return 0;
	
	int i = noOfZeros(n/10);
 
    return (n%10==0) ? (i+1) : i;	
}
 
int main()
{
    int n=4300350;
    
    cout<<noOfZeros(n); 
}









