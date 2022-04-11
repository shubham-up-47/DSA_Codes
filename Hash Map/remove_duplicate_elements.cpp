#include <bits/stdc++.h>
using namespace std;

                                          
vector<int> removeDuplicateElements(int *arr, int n)
{
	vector<int> vtr;
	unordered_map<int,bool>  h;
	
	for(int i=0; i<n; i++)
	{  if(h.count(arr[i]) > 0)
	   continue;
	   
	   h[arr[i]] = true;
	   vtr.push_back(arr[i]);  }
	
	return vtr;
}


int main()
{
	int n;                                                             
	cout<<"Enter size of array: ";                     
	cin>>n;
	
	int *arr = new int[n];
	cout<<"Enter array elements: "; 
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
    vector<int> vtr = removeDuplicateElements(arr,n);
    
	cout<<"\n\nArray elements after removing duplicates: "; 
	for(int i=0; i<vtr.size(); i++)
	cout<<vtr[i]<<" ";
	cout<<endl<<endl;
}

 
 
/*

  8 1 4 2 2 8 9 1 7 
  
*/

 







