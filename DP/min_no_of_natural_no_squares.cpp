#include <bits/stdc++.h>
using namespace std;

 // finding min no of NaturalNoSquares required, to express (n) as sum of NaturalNoSquares 
 // consider all the cases by taking any NaturalNo i from [1,n] & do function call for f(n-i²)       
                                                                                   
int minNoOfNaturalNoSquaresBF(int n)                              // Brute Force { O(n^n) } 
{
	if(n==0)       
	return 0;                         
                                                                                                                        
    int c = INT_MAX;
    for(int i=1; i<=sqrt(n); i++)
	{  int temp = 1 + minNoOfNaturalNoSquaresBF(n - i*i);
	   c = min(c, temp);  }
	                                                                                                                                              
	return c;
}
                                                                      
int minNoOfNaturalNoSquaresM(int *arr, int n)                     // Memorization { O(n*n) }
{
	if(n==0)       
	return 0;
    else if(arr[n]!=-1)
	return arr[n];	
                                                                                                                  
    int c = INT_MAX;   
    for(int i=1; i<=sqrt(n); i++)
	{  int temp = 1 + minNoOfNaturalNoSquaresM(arr, n - i*i);
	   c = min(c, temp);  }
	                                                                 
	arr[n] = c;                    
	return arr[n];
}


int main()
{
	int n=39;
	cout<<"Min no of steps required in reducing "<<n<<" to 1 are: "<<endl;
	
    cout<<minNoOfNaturalNoSquaresBF(n)<<endl;
	
	int arr1[n+1];
	for(int i=0; i<n+1; i++)
	arr1[i] = -1; 
    cout<<minNoOfNaturalNoSquaresM(arr1, n)<<endl; 
   
    int arr2[n+1];                                                // Dynamic Programming { O(n*n) }
    arr2[0] = 0; 
    for(int i=1; i<n+1; i++)
    {
        int c = INT_MAX;
        for(int j=1; j<=sqrt(i); j++)
    	{  int temp = 1 + arr2[i - j*j];
	       c = min(c, temp);  }
	                       
    	arr2[i] = c;
    } 
    cout<<arr2[n]<<endl; 
}





 







