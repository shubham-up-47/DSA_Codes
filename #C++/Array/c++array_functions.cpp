#include <bits/stdc++.h>
using namespace std;


void printArray(int *arr, int n)
{
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}


int main()                                  // most of these functions are in  #include<algorithm>  header file
{ 
    int n= 8;
	int arr[8] = {3,0,2,7,7,1,9,4};
	 
    sort(arr, arr+n);  	 
	 
  // binary search concept is used to calculate lower_bound() & upper_bound() for sorted array
    auto p = lower_bound(arr, arr+n, 7);    // returns iterator pointing to 1st element which has value >= 7   {O(logn)} 
    cout<<"The lower bound of 7: "<<p-arr<< endl;
    auto q = upper_bound(arr, arr+n, 7);    // returns iterator pointing to 1st element which has value > 7   {O(logn)}
    cout<<"The upper bound of 7: "<<q-arr<<endl; 
	
	
    cout<<endl;
    
    
    reverse(arr, arr+n);                                                                        // reverse
    printArray(arr,n); 
     
    sort(arr, arr+n);                                                                           // sort
    printArray(arr,n); 
    
    
    cout<<endl;
    
    
    cout<<"Size of Array is: "<< sizeof(arr)/sizeof(arr[0]) <<endl;                             // size
    cout<<"Max element is: "<< *max_element(arr, arr+n) <<endl;                                 // max element
    cout<<"Min element is: "<< *min_element(arr, arr+n) <<endl;                                 // min element
    cout<<"Sum of array elements is: "<< accumulate(arr, arr+n, 0) <<endl;                      // sum of elements (0 = initial sum)
    cout << "Frequency of 7 in array: "<< count(arr, arr+n, 7) <<endl;                          // frequency of element
    find(arr, arr+n, 5)!=arr+n ? cout<<"5 is present\n" : cout<<"5 is not present\n";           // simple search
    binary_search(arr, arr+n, 3)==true ? cout<<"3 is present\n" : cout<<"3 is not present\n";   // binary search
}





















