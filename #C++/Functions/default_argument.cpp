#include <bits/stdc++.h>
using namespace std;

// default argument in UserDefinedFunction = (initialize its value bcz no input for it), (defined at right end only)                 

int arraySum(int *arr, int n, int i=0, int sum=0)  // default argument in UserDefinedFunction  
{
	if(i==n)
	return sum;
	
	sum += arr[i];
	int r = arraySum(arr, n, i+1, sum);
	
	return r;
}


int main()
{ 
	int arr[] = {4,1,0,7,3,2};
	
	cout << arraySum(arr, 6) << endl;
}













