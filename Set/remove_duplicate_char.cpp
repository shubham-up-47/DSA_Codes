#include <bits/stdc++.h>
using namespace std;


/*

In OrderdSet, dataIsStored inSortedOrder & duplicateValues areNotAllowed (bcz it uses BST implementation)   
In UnorderedSet, dataIsStored inUnsortedOrder & duplicateValues areNotAllowed (bcz it uses Hash Table implementation)   
           
In MultiSet, dataIsStored inSortedOrder & duplicateValues areAllowed (bcz it uses BST implementation)  
In MultiSet, insert() erase() binary_search() lower_bound() upper_bound() takes O(logn) time  

*/


 // Unordered Set = (stores list of (Key)), (O(1)), (unordered_set< datatype >), (it doesn't store duplicate keys)             
 
 // (set.count(k)=0 -> Key k is not present) &  (set.count(k)=1 -> Key k is present)         
                                          
string removeDuplicateChars(string str)
{
	string r;
	unordered_set<char>  set;
	
	for(int i=0; i<str.size(); i++)
	{ 
	   if(set.count(str[i])==0)                              // if current char is unique, then include it 
	   {  r += str[i];
	      set.insert(str[i]);  }
    }
    
	return r;
}


int main()
{
	string str;
	cout<<"Enter input string: "; 
    cin>>str;
	
    string s = removeDuplicateChars(str); 
	cout<<"\n\nOutput string (after removing duplicate chars): "<<s<<endl<<endl;
}

 
 
/*

  shuubhams 
  
*/

 










