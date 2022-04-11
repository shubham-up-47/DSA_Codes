#include <bits/stdc++.h>
using namespace std;

// (char, ASCII)   (\0, 0)   (\t, 9)   (\n, 10)   ( , 32)                                                                                                              

int main()
{ 
	char c;
	cin.get(c);
	 
    cin.clear();              // clear buffer in C++
    fflush(stdin); 
	char arr[10];             // first clear buffer before taking input, so avoid char array, use string 
	cin.getline(arr,10);

	string str;
	getline(cin,str);
	 
    cout<<c<<endl;
    cout<<arr<<endl;    
    cout<<str<<endl; 
}
















