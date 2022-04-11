#include<iostream>
using namespace std;

int main()
{    char c;       int n;
     cout<<"Enter dimention: ";
     cin>>n;
	
   	 for(int i=0;i<n;i++)
	 {
		char c='A';
		
		for(int j=0;j<n;j++,c++)
        cout<<c<<" ";
		
		cout<<endl;
	 }

}

