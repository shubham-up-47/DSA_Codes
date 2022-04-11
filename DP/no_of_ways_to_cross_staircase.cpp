#include <bits/stdc++.h>
using namespace std;

 // count no of ways to cross (n steps staircase) when (1/2/3 steps move are allowed at a time)
  
int staircaseBF(int n)                              // Brute Force { O(3^n) }  
{
	if(n==0||n==1||n==2)
	return (n==2) ? 2 : 1;
  
	int r = staircaseBF(n-1) + staircaseBF(n-2) + staircaseBF(n-3);
	
	return r;
}

int staircaseM(int *arr, int n)                     // Memorization { O(n) }
{
	if(n==0||n==1||n==2)
	return (n==2) ? 2 : 1;
    else if(arr[n]!=-1)
	return arr[n];	
	
	arr[n] = staircaseM(arr,n-1) + staircaseM(arr,n-2) + staircaseM(arr,n-3);
	
	return arr[n];
}


int main()
{
	int n=7;
	cout<<"No of ways to cross staircase of "<<n<<" steps: "<<endl;
	
    cout<<staircaseBF(n)<<endl;
	
	int arr1[n+1];
	for(int i=0; i<n+1; i++)
	arr1[i] = -1; 
    cout<<staircaseM(arr1, n)<<endl; 
   
    int arr2[n+1];                                  // Dynamic Programming { O(n) }
    arr2[0] = 1;
    arr2[1] = 1;
    arr2[2] = 2;
    for(int i=3; i<n+1; i++)
    arr2[i] = arr2[i-1] + arr2[i-2] + arr2[i-3]; 
    cout<<arr2[n]<<endl; 
}









