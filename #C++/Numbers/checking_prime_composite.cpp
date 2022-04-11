#include <iostream>
#include <cmath>
using namespace std;


int main()
{ int n;
  cout<<"Enter no: ";
  cin>>n;
  
  for( int i=2; n==1||i<=sqrt(n); i++ )
  {
   	 if( n==1||n%i==0 )
  	 {  cout<<"n is Composite"<<endl;	
        exit(1); }
  }
  
  cout<<"n is Prime"<<endl;
}
















