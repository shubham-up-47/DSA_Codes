#include <bits/stdc++.h>
using namespace std;


bool isMinHeap(int arr[], int n)
{
	for(int i=0; 2*i+1<n; i++)
	{
		if(arr[i] > arr[2*i+1] || arr[i] > arr[2*i+2])
		return 0; 
	}
	
	return 1;
}
 

int main()
{  
    int pq[] = {0,5,1,14,12,9,6,100};
  
    cout<<"Is given heap a min heap: ";
    
    if(isMinHeap(pq,8))
    cout<<"Yes"<<endl;
    else
	cout<<"No"<<endl; 
}

                                                                                           
 /*
   
            0            
           / \ 
          /   \ 
         5     1                       (Min Heap) = (parent data < child data)
        /\     /\
       /  \   /  \
     100  12 9    6       
     /		
	/
   14
   	
  pq[] = {0,5,1,14,12,9,6,100} 	       (Min Priority Queue)                                   
 
 */
 
  






