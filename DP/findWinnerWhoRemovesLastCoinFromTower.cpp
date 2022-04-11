#include <bits/stdc++.h>
using namespace std;

 // finding winner (who removes last coin from the tower), when A & B make alternate turns to remove (1 / x / y) coins from tower of (n) coins    
 // A removes first coin, and each uses best move to win the game       
   
int main()
{
	int n=15, x=2, y=5;
	
    bool arr[n+1];                                     // Dynamic Programming  
    arr[0] = 0;
	arr[1] = 1; 
    for(int i=2; i<n+1; i++)                           // if A loses any of (i-1)/(i-x)/(i-y) game, then he will definately win game (i)  
    {
       if(i-1>=0 && !arr[i-1])        
	   arr[i] = 1;    
       else if(i-x>=0 && !arr[i-x])
	   arr[i] = 1;
       else if(i-y>=0 && !arr[i-y])
	   arr[i] = 1;
       else
	   arr[i] = 0;
    }


    if(arr[n]==1)
	cout<<"A won"<<endl;
	else
    cout<<"B won"<<endl; 
}










