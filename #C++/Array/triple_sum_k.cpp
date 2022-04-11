#include <bits/stdc++.h>
using namespace std;


int pairSumK(int *arr, int n, int k)
{
	int c=0;
	
	for(int i=0,j=n-1;  i<j;  )
	{
		if(arr[i]+arr[j] < k)
		i++;
		else if(arr[i]+arr[j] > k)
		j--; 
		else
		{
		    if(arr[i]==arr[j])            
			{   int n = j-i+1;
			    c += (n*(n-1))/2;             
				return c;	}	
		    else       	                    
			{   int iTemp=i, jTemp=j;              
		    	while(arr[i]==arr[iTemp] && i<jTemp)
	    		i++;
	    		while(arr[j]==arr[jTemp] && iTemp<j)
	     	    j--;
	       		
	    		c += (i-iTemp)*(jTemp-j);   }              
		} 
	}
	 
    return c;	
}


int tripletSumK(int *arr, int n, int k)       // finding count of all pairs (arr[x],arr[y],arr[z]) where (arr[x]+arr[y]+arr[z]=k)    { O(n²logn) }               
{
	int c=0; 
	
	sort(arr, arr+n);                         // sort already to improve time complexity, otherwise n times sorting
	
	for(int i=0; i<n; i++)
	c += pairSumK(arr+i+1, n-i-1, k-arr[i]);  // select a element on LHS, then calculate pair sum for RHS                                    
	
	return c; 
}


int main()
{ 
	int arr[6] = {2,1,2,3,1,0};
	
	cout<<tripletSumK(arr, 6, 5); 
}












 
 
 
 
 
