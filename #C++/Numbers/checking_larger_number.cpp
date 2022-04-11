#include<iostream>
using namespace std;

int main()
{
  int a,b;
  cout<<"Enter 2 numbers to compare: ";
  cin>>a>>b;
  
  if(a>b)
  cout<<"\na is bigger";
  else if(b>a)
  cout<<"\nb is bigger";
  else
  cout<<"\nBoth are equal";	 
}

