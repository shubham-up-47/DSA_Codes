#include <bits/stdc++.h>
using namespace std;
 
  // Input: K arrays which are sorted individually 
  // Output: Final sorted array after merging
  
vector<int> merge_K_SortedArrays(vector<vector<int>*> arr)                       
{  
    vector<int> r;                                         // MinPriorityQueue storing Triplet { element value, {array index,element index in array} } 
	priority_queue<  pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>>,  greater<pair<int,pair<int,int>>>  >     pq;   
                                                
	for(int i=0; i<arr.size(); i++)       
	pq.push( {arr[i]->at(0), {i,0}} );	                    
    
    while(pq.size() != 0)                                                       
    {                                                  
	   pair<int,pair<int,int>>  temp = pq.top();           // remove minElement from PriorityQueue & store in OutputSortedArray  
	   pq.pop(); 
	   r.push_back(temp.first);
	   
	   int i=temp.second.first, j=temp.second.second;      // remove nextElement from minElementContainingSortedArray & store in PriorityQueue 
	   if(j+1 < arr[i]->size())
	   pq.push( {arr[i]->at(j+1), {i,j+1}} );	           // Triplet for { arr[i]->(j) } will be { arr[i]->(j), {i,j} }  
    }
	
    return r;
} 
 
void printVector(vector<int> arr)
{
	for(int i=0; i<arr.size(); i++)
	cout<<arr[i]<<" ";
}
           
int main()
{  
	int k;
	cout<<"Enter count of sorted arrays: ";
	cin>>k; 
	
	vector<vector<int>*> arr;  
    cout<<"\n\nEnter each sorted array in each line (use -1 as terminator):\n";
	for(int i=0; i<k; i++)
    {  vector<int> *vtr = new vector<int>(); 
	    
	   int x;
	   cin>>x;
	   
       while(x != -1)
	   {  vtr->push_back(x); 
	      cin>>x;  }
		   
	   arr.push_back(vtr);	}
   
    vector<int> vtr = merge_K_SortedArrays(arr);           // highly optimized solution  
    cout<<"\n\n'Final sorted array' after 'merging K sorted arrays' is: ";
    printVector(vtr); 
    cout<<endl<<endl; 
}
 



 

/* 
      (n=5 i.e. input are 5 sorted arrays) 
    
 5
 2 3 4 12 -1 
 1 5 7 9 -1
 0 4 6 8 15 15 129 -1
 7 15 22 37 -1
 1 6 10 19 -1
 
*/

 
 
   



