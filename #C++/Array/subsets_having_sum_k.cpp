#include <bits/stdc++.h>
using namespace std;
 
 // calculating (subsets of integerArray) & (subsets of characterArray(string)) are same                                                                                                                                     
           
int returnSubsetsHavingSumK(int arr[], int n, int k, int subsets[][50])
{
	if(n==0 && k!=0)
	return 0;
	else if(n==0 && k==0)
	{  subsets[n][0]=0;
	   return 1;  }
                                       
             	                                                       
	int nS1, nS2, nS=0;
	int subsets1[1000][50], subsets2[1000][50];
                                                                                                  	                                                 
    nS1 = returnSubsetsHavingSumK(arr+1, n-1, k, subsets1);            // excluding arr[0]
	for(int i=0; i<nS1; i++,nS++)
	{ 	subsets[nS][0] = subsets1[i][0];
 
	   	for(int j=1; j<subsets1[i][0]+1; j++)
	   	subsets[nS][j] = subsets1[i][j];     }

    nS2 = returnSubsetsHavingSumK(arr+1, n-1, k-arr[0], subsets2);     // including arr[0]
	for(int i=0; i<nS2; i++,nS++)
	{ 	subsets[nS][0] = subsets2[i][0]+1;
        subsets[nS][1] = arr[0];
        
	   	for(int j=2; j<subsets2[i][0]+2; j++)
	   	subsets[nS][j] = subsets2[i][j-1];    }
	
	
	return nS; 
}


int main()
{  
  int arr[3] = {1, 5, 6};

  int subsets[1000][50];                                               // first column (subsets[n][0]) stores size of (n)th subsets having sum K      
  int n = returnSubsetsHavingSumK(arr, 3, 6, subsets);
  
  for(int i=0; i<n; i++)
  {  for(int j=1; j<=subsets[i][0]; j++)
  	 cout<<subsets[i][j]<<" ";
	 cout<<endl;  }  
}




 












