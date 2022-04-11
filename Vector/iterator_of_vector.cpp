#include <bits/stdc++.h>
using namespace std;

 
int main()
{
    vector<int> v = {2, 4, 7, 1}; 
    vector<int>::iterator it;                 // iterator of vector array
   
    cout<<"Elements of vector array are: ";
	for(it=v.begin(); it!=v.end(); it++)      // (v.begin() = address of first element)  &  (v.end() = address stored after iterating last element) 
	cout<<*it<<" ";                           // printing value         
	cout<<endl<<endl;
}












 
 










