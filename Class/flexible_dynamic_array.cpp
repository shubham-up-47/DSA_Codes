#include <bits/stdc++.h>
using namespace std;


class DynamicArray
{
	int *arr;                                      // dynamic array pointer
	int nextI;                                     // starting index of unoccupied array
	int capacity;                                  // capacity(total size) of dynamic array
          	
	  public:
	DynamicArray()                                 // default constructor
	{  arr = new int[5];
	   nextI = 0;
	   capacity = 5;  }
	
	DynamicArray(DynamicArray const &d)            // copy constructor
	{  arr = new int[d.capacity];
	
	   for(int i=0; i<d.nextI; i++)
	   arr[i] = d.arr[i];                          // deep copy  
	   nextI = d.nextI;
	   capacity = d.capacity;	}
	
	void operator=(DynamicArray const &d)          // user defined copy assignment operator
	{  arr = new int[d.capacity];
	
	   for(int i=0; i<d.nextI; i++)
	   arr[i] = d.arr[i];                          // deep copy  
	   nextI = d.nextI;
	   capacity = d.capacity;	}
	
	void add(int x)                                // adding element at end 
	{ 	if(nextI==capacity)
		{  int *brr = new int[2*capacity]; 
    	   for(int i=0; i<capacity; i++)
    	   brr[i] = arr[i]; 
    	   
    	   delete [] arr;
    	   arr = brr; 
    	   capacity *= 2;	}
     		
		arr[nextI] = x;
		nextI++;  	}
	
	void add(int i, int x)                         // adding element at ith index
	{   if(i<nextI)
	    arr[i] = x;
	    else if(i==nextI)
	    add(x);
	    else 
	    return;   }
	
	int get(int i) const                           // returning element at ith index      
    {   if(i<nextI)
        return arr[i];
        else
        return -1;  } 	
          
    void print() const                             // printing array    
    {   for(int i=0; i<nextI; i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;  } 
};

 
int main()
{
   DynamicArray d1;
   for(int i=1; i<7; i++)
   d1.add(10*i);                                   // adding element at end
   cout<<"d1: ";   d1.print();
   d1.add(0,100);                                  // adding element at ith index   
   cout<<"d1[0]: "<<d1.get(0)<<endl;               // returning element at ith index  
   cout<<"d1: ";   d1.print();
      
   DynamicArray d2(d1);                            // user defined copy constructor
   cout<<"\nd2: ";   d2.print(); 
    
   DynamicArray d3;
   d3 = d1;                                        // user defined copy assignment operator  
   cout<<"d3: ";   d3.print();  
}

  // (inbuilt copy constructor) & (inbuilt copy assignment operator) do shallow copy (copying address of memory where data is stored) 
  // (user defined copy constructor) & (user defined copy assignment operator) do deep copy (copying data one by one in new array) 








  


 
