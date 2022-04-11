#include <bits/stdc++.h>
using namespace std;

 
int main()                                 
{ 
    int n= 8;
	int arr[8] = {3,0,2,7,7,1,9,4};
	
    find(arr, arr+n, 5)!=arr+n ? cout<<"5 is present\n" : cout<<"5 is not present\n";           // simple search
    binary_search(arr, arr+n, 3)==true ? cout<<"3 is present\n" : cout<<"3 is not present\n";   // binary search 
    
    
            // binary search concept is used to calculate lower_bound() & upper_bound()
   
   
    auto p = lower_bound(arr, arr+n, 7);    // returns iterator pointing to 1st element which has value >= 7   {O(logn)} 
    cout<<"The lower bound of 7: "<<p-arr<< endl;
    auto q = upper_bound(arr, arr+n, 7);    // returns iterator pointing to 1st element which has value > 7   {O(logn)}
    cout<<"The upper bound of 7: "<<q-arr<<endl;  
}












