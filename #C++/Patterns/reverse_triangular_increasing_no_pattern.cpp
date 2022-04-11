#include<iostream>
using namespace std;

int main()
{              
   int n,x=1;
   cout<<"Enter no of rows: ";         // n<=30
   cin>>n;
                
   for( int i=1 ; i<=n ; i++ )
   {  
       for( int j=1 ; j<=n-i ; j++ )
       cout<<"    ";	
          
       for( int k=1 ; k<=i ; k++,x++ )
       {  if(x/10==0)
          cout<<x<<"   ";
		  else if(x/100==0)	
		  cout<<x<<"  ";
		  else
		  cout<<x<<" ";
 	    }
   	   cout<<endl;
   }           
}  



