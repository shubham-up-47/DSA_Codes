#include <bits/stdc++.h>
using namespace std;


int findLastAppearenceIndex(int *arr, int n, int x)
{
	if(n==0)
	return -1;
	else if(arr[n]==x)
	return n; 
	
	int r = findLastAppearenceIndex(arr, n-1, x);
	
	return r;
}


int main()
{
	
	
	
	
	

 
 
 

}









