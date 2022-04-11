#include<iostream>
using namespace std;

int main()
{  int a,b;
   cout<<"Enter values of a & b: ";
   cin>>a>>b;
   
   bool equal=(a==b);
   bool a_big=(a>b);
   bool b_big=(b>a);
   
   cout<<"\nAre they equal: "<<equal<<endl;
   cout<<"Is a bigger: "<<a_big<<endl;
   cout<<"Is b bigger: "<<b_big<<endl;
}

