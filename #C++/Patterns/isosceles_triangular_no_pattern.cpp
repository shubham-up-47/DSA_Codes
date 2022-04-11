#include<iostream>
using namespace std;

int main()
{
	int n;
 	cout<<"Enter dimentions: ";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=n-i;j++)
		cout<<" ";
		
		int k;
		for(k=1;k<=i;k++)
		cout<<k;
		
		k=k-2;
		for(int l=1;l<i;l++,k--)
	    cout<<k;
	    
	    cout<<endl;
 	}
 
}

