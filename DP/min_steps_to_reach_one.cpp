#include <bits/stdc++.h>
using namespace std;

 // finding min steps required in reducing (n) to (1), by applying operations (n = n-1) or (n = n/2 if n%2==0) or (n = n/3 if n%3==0)
  
int minStepsToReachOneBF(int n)                              // Brute Force { O(3^n) } 
{
	if(n==1)       
	return 0;
  
	int c1, c2=INT_MAX, c3=INT_MAX;
	c1 = minStepsToReachOneBF(n-1);
	if(n % 2 == 0)
	c2 = minStepsToReachOneBF(n/2);
	if(n % 3 == 0)
	c3 = minStepsToReachOneBF(n/3);
	                      
	return (1 + min(c1, min(c2,c3)));
}

int minStepsToReachOneM(int *arr, int n)                     // Memorization { O(n) }
{
	if(n==1)       
	return 0;
    else if(arr[n]!=-1)
	return arr[n];	
  
  
	int c1, c2=INT_MAX, c3=INT_MAX;
	c1 = minStepsToReachOneM(arr, n-1);
	if(n % 2 == 0)
	c2 = minStepsToReachOneM(arr, n/2);
	if(n % 3 == 0)
	c3 = minStepsToReachOneM(arr, n/3);
	                       
	arr[n] = 1 + min(c1, min(c2,c3));
	
	
	return arr[n];
}


int main()
{
	int n=13;
	cout<<"Min no of steps required in reducing "<<n<<" to 1 are: "<<endl;
	
    cout<<minStepsToReachOneBF(n)<<endl;
	
	int arr1[n+1];
	for(int i=0; i<n+1; i++)
	arr1[i] = -1; 
    cout<<minStepsToReachOneM(arr1, n)<<endl; 
   
    int arr2[n+1];                                           // Dynamic Programming { O(n) }
    arr2[1] = 0; 
    for(int i=2; i<n+1; i++)
    {
        int c1, c2=INT_MAX, c3=INT_MAX;
    	c1 = arr2[i-1];
    	if(i % 2 == 0)
    	c2 = arr2[i/2];
    	if(i % 3 == 0)
    	c3 = arr2[i/3];
	                       
    	arr2[i] = 1 + min(c1, min(c2,c3));
    } 
    cout<<arr2[n]<<endl; 
}



















