#include <bits/stdc++.h>
using namespace std;
 
 // calculating (subsets of integerArray) & (subsets of characterArray(string)) are same
 
int subsets[100][50];               // first column (subsets[nS+i][0]) stores size of (nS+i)th subsets                                                                                                                                            

int returnArraySubsets(int *arr, int n)
{
	if(n==0)
	{  subsets[0][0]=0;
	   return 1;  }
	
	int nS = returnArraySubsets(arr+1, n-1);
	
	for(int i=0; i<nS; i++)
	{
	   	subsets[nS+i][0] = 1 + subsets[i][0];
	   	subsets[nS+i][1] = arr[0];
	   	
	   	for(int j=2; j<subsets[i][0]+2; j++)
	   	subsets[nS+i][j] = subsets[i][j-1]; 
	}
	
	return 2*nS; 
}


int main()
{  
  int arr[] = {15,20,12};
  
  int n = returnArraySubsets(arr, 3);
  
  for(int i=0; i<n; i++)
  {  for(int j=1; j<=subsets[i][0]; j++)
  	 cout<<subsets[i][j]<<" ";
	 cout<<endl;  }  
}









 


