#include <bits/stdc++.h>
using namespace std;


void towerOfHanoi(int n, char S, char A, char D)
{
	if(n==0)
    return;  
	
	towerOfHanoi(n-1, S, D, A);
	cout<<S<<" "<<D<<endl;
	towerOfHanoi(n-1, A, S, D); 
	
	return;
}


int main()
{
    towerOfHanoi(3, 'A', 'B', 'C'); 
}




















