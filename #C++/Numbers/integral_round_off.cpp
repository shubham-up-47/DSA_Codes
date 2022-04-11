#include<iostream>
using namespace std;

int main()
{  
   float n;
   int i;
	
   cout<<"Enter no: ";
   cin>>n;

   i=n;	
	
   if( ((n-i)<0.5) || ((n-i)==0.5) && (i%2==0) )
   cout<<"\nRound off No: "<<i;
   else 
   cout<<"\nRound off No: "<<i+1;
 
}

