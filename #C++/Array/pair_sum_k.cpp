#include <bits/stdc++.h>
using namespace std;


int pairSumK(int *arr, int n, int k)             // finding count of all pairs (arr[i], arr[j]) where (arr[i] + arr[j] = k)    { O(nlogn) }                                 
{
	int c=0;
	sort(arr, arr+n);
	
	for(int i=0,j=n-1;  i<j;  )
	{
		if(arr[i]+arr[j] > k)
		j--;
		else if(arr[i]+arr[j] < k)
		i++;
		else
		{
		    if(arr[i]==arr[j])                         // then all elemwents between (i to j) will form pairSumK 
			{   int n = j-i+1;
			    c += (n*(n-1))/2;                      // nC2
				return c;	}	
		    else       	                               // then all elemwents between (i to iT) & (jT to j) will form pairSumK
			{   int iTemp=i, jTemp=j;              
		    	while(arr[i]==arr[iTemp] && i<jTemp)
	    		i++;
	    		while(arr[j]==arr[jTemp] && iTemp<j)
	     	    j--;
	       		
	    		c += (i-iTemp)*(jTemp-j);   }          // nC1 X mC1           
		} 
	}
	 
    return c;	
}


int main()
{ 
	int arr[6] = {1,2,3,1,4,2};
	
	cout<<pairSumK(arr, 6, 5); 
}























