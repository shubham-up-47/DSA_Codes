#include<iostream>
using namespace std;

int main()
{     int n;
      cout<<"Enter n: ";
      cin>>n;
      
      for(int i=1;i<=n;i++)
      {
      	 for(int j=i;j<=2*i-1;j++)
      	 { 
		   if(j/10==0)  
		   cout<<j<<"  ";
		   else  
		   cout<<j<<" ";
         }
         
      	 cout<<endl;
	  }
}






