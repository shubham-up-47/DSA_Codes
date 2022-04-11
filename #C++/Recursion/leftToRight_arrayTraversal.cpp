#include <bits/stdc++.h>
using namespace std;


int findFirstAppearenceIndex(int *arr, int n, int x)
{
	if(n==0)
	return -1;
	else if(arr[0]==x)
	return 0; 
	
	int r = findFirstAppearenceIndex(arr+1, n-1, x);
	
	return (r==-1) ? -1 : (r+1);
}


int main()
{
	
	
	
	
	

 
 
 

}















