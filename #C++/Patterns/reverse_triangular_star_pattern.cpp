#include<iostream>
using namespace std;

int main()
{  int n;
   cout<<"Enter dimentions: ";
   cin>>n;
   
   for(int i=0;i<n;i++)
   {
   	  for(int j=0;j<n-i;j++)
   	  cout<<" ";
   	
   	  for(int k=0;k<i;k++)
   	  cout<<"*";
   	
   	  cout<<endl;
   }
}

