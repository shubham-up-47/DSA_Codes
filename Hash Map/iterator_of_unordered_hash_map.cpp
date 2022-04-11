#include <bits/stdc++.h>
using namespace std;

 
int main()
{ 
	unordered_map<string,int>  h = { {"abc0",1}, {"abc1",2}, {"abc2",3}, {"abc3",4}, {"abc4",5}, {"abc5",6} };
	 
	unordered_map<string,int>::iterator it1, it2;                    // iterator of unordered hash map
	
	
	cout<<"Unordered hash map elements are: \n";                     // printing map 
	cout<<"[Key]  [Value]\n";
	for(it1=h.begin(); it1!=h.end(); it1++)                            
	cout<<" "<<it1->first<<" => "<<it1->second<<endl;                // (Key,Value) are printed randomly bcz unordered hash map  
	 
	
	it1 = h.find("abc3");                                            // finds Value corresponding Key    
	cout<<"\n "<<it1->first<<" => "<<it1->second<<endl;
	h.erase(it1);                                                    // erases (Key,Value) at [it1]
	if(h.count("abc3")==0)
	cout<<"\nabc3 is absent"<<endl;
	
	
	it1 = h.find("abc4");
	it2 = h.find("abc2");	
	h.erase(it1, it2);                                               // erases (Key,Value) in range [it1, it2) i.e. including it1 & excluding it2
	
	
	cout<<"\nUnordered hash map elements are: \n";                   // printing map              
	cout<<"[Key] [Value]\n";
	for(it1=h.begin(); it1!=h.end(); it1++)
	cout<<" "<<it1->first<<" => "<<it1->second<<endl; 
}



/*

    ->   Iterator  
*used to travel on a data structure
*used to find & erase some specific elements
*vector, set & map have their corresponding iterators
*for unordered set/map iteration will occur randomly
*for vector, ordered set/map iteration will occur in order of insertion of elements
*h.begin() = address of random element acts as beginning element 
*h.end() = address stored after iterating last element


*/








 
 
 
 
