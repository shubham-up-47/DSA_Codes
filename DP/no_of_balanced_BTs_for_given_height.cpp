#include <bits/stdc++.h>
using namespace std;

long m = pow(10,9) + 7;

 // finding count of all possible BalancedBinaryTrees (Balanced BTs) for given height (h)
 // BalancedBinaryTrees = BT in which |height of LeftChild BT - height of RightChild BT| <= 1
                                                         
long noOfBalancedBTsBF(int h)                                        // Brute Force { O(2^n) } 
{
	if(h==0 || h==1)       
	return 1;
  
	long c1 = noOfBalancedBTsBF(h-1);
	long c2 = noOfBalancedBTsBF(h-2);
                
	return (c1*c1 + c1*c2 + c2*c1)%m;
}
                                                                                           
long noOfBalancedBTsM(long *arr, long h)                             // Memorization { O(n) }
{
	if(h==0 || h==1)       
	return 1;
    else if(arr[h]!=-1)
	return arr[h];	
   
	long c1 = noOfBalancedBTsM(arr, h-1)%m;                         // applying Modulo Arithmetic
	long c2 = noOfBalancedBTsM(arr, h-2)%m; 
	
	arr[h] = ( ( (c1*c1)%m + (c1*c2)%m )%m + (c2*c1)%m )%m; 
	return arr[h];
}


int main()
{
	long h = 5;
	cout<<"Total no of Balanced BTs possible for given height h="<<h<<" are: "<<endl;
	
    cout<<noOfBalancedBTsBF(h)<<endl;
	
	long arr1[h+1];
	for(int i=0; i<h+1; i++)
	arr1[i] = -1; 
    cout<<noOfBalancedBTsM(arr1, h)<<endl; 
   
    long arr2[h+1];                                                  // Dynamic Programming { O(n) }
    arr2[0] = 1; 
    arr2[1] = 1;
    for(int i=2; i<h+1; i++)
    arr2[i] = (arr2[i-1]*arr2[i-1] + arr2[i-1]*arr2[i-2] + arr2[i-2]*arr2[i-1])%m;  
    cout<<arr2[h]<<endl; 
}





 
 
 
 




 
