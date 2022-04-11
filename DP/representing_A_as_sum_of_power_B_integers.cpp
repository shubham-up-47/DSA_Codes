#include <bits/stdc++.h>
using namespace std;

 // finding total ways to represent 'a' as sum of power 'b' integers 
 // consider all the cases by taking any no i from [1, a] & do function call for f(a - i^b)       
                                                                                   
int totalWaysToRepresent_a_AsSumOfPower_b_IntegersBF(int a, int b, int i=1)                 // we can't write M or DP for this
{
	if(a==0)       
	return 1;  
	else if(a<0 || pow(i,b)>a)
	return 0;                       
                                                                                                                        
    int c1 = totalWaysToRepresent_a_AsSumOfPower_b_IntegersBF(a-pow(i,b), b, i+1);          // including i^b
    int c2 = totalWaysToRepresent_a_AsSumOfPower_b_IntegersBF(a, b, i+1);                   // excluding i^b
	                                                                                                                                              
	return (c1 + c2);
}
                              

int main()
{
	int a=360, b=2;
	
	cout<<"Total ways to represent "<<a<<" as sum of power "<<b<<" integers are: "; 
    cout<<totalWaysToRepresent_a_AsSumOfPower_b_IntegersBF(a, b)<<endl; 
}





 





