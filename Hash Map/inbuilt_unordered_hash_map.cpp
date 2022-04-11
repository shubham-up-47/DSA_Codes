#include <bits/stdc++.h>
using namespace std;

 // Unordered Hash Map = (Table of (Key,Value)), (O(1)), ( unordered_map<d1,d2> ), (default Value of new Key is 0)                                            
 
int main()
{
	unordered_map<string,int>  h;                                                  // (Key,Value) = (string,int)
		
	pair<string,int>  p("abc",1);                                                  // (first,second) = (string,int)                       
	h.insert(p);                                                                   // insertingNewKey 1
	
	h["def"] = 2;                                                                  // insertingNewValue 1
	cout<<"Current size of UnorderedHashMap: "<<h.size()<<endl;                    // size i.e. total no of Keys present 
	
	cout<<"Value of Key 'ghi': "<<h["ghi"]<<endl;                                  // insertingNewKey 2
	cout<<"\nCurrent size of UnorderedHashMap: "<<h.size()<<endl;
	
	cout<<"Value of Key 'abc': "<<h["abc"]<<endl;                                  // getValue 1  
	cout<<"Value of Key 'abc': "<<h.at("abc")<<endl;                               // getValue 2                         
	
	if(h.count("ghi") > 0)                                                         // it returns (0 / 1) i.e. count of that Key 
	cout<<"'ghi' is present"<<endl;
	
	h.erase("ghi");                                                                // delete 
	cout<<"\nCurrent size of UnorderedHashMap: "<<h.size()<<endl; 
	
	if(h.count("ghi") > 0)                                                         // search
	cout<<"'ghi' is present"<<endl;
	else
	cout<<"'ghi' is absent"<<endl;
}

 
 
/*

  [Key]   [Value]
  
   abc       1
   def       2       
   ghi       0


*/


/* 

    ->    Unordered Hash Map     { O(1) }
    
*it doesn't allow duplicate keys & default value of new key is 0   
*implemented using Hash Table conept                                  
*it's each node stores (Key,Value)                                           
*datatype of Key & Value is decided by us
*highly optimized datastructure but data stored in it is unordered 
  
   
*/





 

