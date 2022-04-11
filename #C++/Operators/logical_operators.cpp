#include<iostream>
using namespace std;

int main()
{
  int a,b,c,d, x=1,y=1; 
  
  
  a=5;   b=a+2;   c=a++;   d=++a;
  cout<<"a b c d = "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
 
 
  a+=3;  a*=2;  a-=4;  a/=2;  a%=3;
  cout<<"a = "<<a<<endl;
 
 
  cout<<"x = "<<--x<<" ";    cout<<x--<<endl;     // normal behavior
  cout<<"y = "<<--y<<" "<<y--<<endl;              // abnormal behavior
}




