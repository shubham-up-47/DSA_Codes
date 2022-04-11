#include<iostream>
using namespace std;

int main()
{    int n;
     cout<<"Enter dimention: ";
     cin>>n;
     cout<<"\n\n";
	
   	 for(int i=0;i<n;i++)
	 {
	    char c='A'+i;
		
		for(int j=0;j<n;j++,c++)
        cout<<c<<" ";
		
		cout<<endl;
	 }

}

