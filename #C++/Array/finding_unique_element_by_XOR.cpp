#include <bits/stdc++.h>
using namespace std;

 // find unique element if array having (n+1 distinct numbers) where (1 number is unique) & (n numbers are repeating m times) & (m>1) 
 // taking XOR of all to find unique element bcz (x^x=0) so unique element will be in last

int arrayXOR(int *arr, int n)             // { O(n) }
{
	if(n==0)
	return -1;
	
	for(int i=1; i<n; i++)
	arr[i] = arr[i]^arr[i-1];
	
	return arr[n-1]; 
}


int main()
{











}














