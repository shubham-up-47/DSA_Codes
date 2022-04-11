#include <bits/stdc++.h>
using namespace std;


void printVector(vector<int> &vtr)
{ 	for(int i=0; i<vtr.size(); i++)
	cout<<vtr[i]<<" ";
	cout<<endl;   }
 
void printDynamicVector(vector<int> *vtr)
{ 	for(int i=0; i<vtr->size(); i++)
	cout<<vtr->at(i)<<" ";
	cout<<endl;   }


int main()                                                   // most of these functions are in  #include<algorithm>  header file
{
	int n=9, arr[9] = {3,0,2,4,7,7,1,9,4}; 
    vector<int> vtr(arr, arr+n);                             // vector initialized by values of arr                           
  
    
    cout<<"Size of vector is: "<< vtr.size() <<endl;                                                              // size
    cout<<"Max element is: "<< *max_element(vtr.begin(),vtr.end()) <<endl;                                        // max element
    cout<<"Min element is: "<< *min_element(vtr.begin(),vtr.end()) <<endl;                                        // min element
    cout<<"Sum of vector elements is: "<< accumulate(vtr.begin(),vtr.end(),0) <<endl;                             // sum of elements (0 = initial sum)
    cout << "Frequency of 7 in vector: "<< count(vtr.begin(),vtr.end(),7) <<endl;                                 // frequency of element
    find(vtr.begin(),vtr.end(),5)!=vtr.end() ? cout<<"5 is present\n" : cout<<"5 is not present\n";               // simple search
    binary_search(vtr.begin(),vtr.end(), 3)==true ? cout<<"3 is present\n" : cout<<"3 is not present\n";          // binary search
    cout<<"Distance between first and max element: "<< distance(vtr.begin(), max_element(vtr.begin(),vtr.end())); // distance


    cout<<endl<<endl<<endl;
    
    
    auto p = lower_bound(vtr.begin(), vtr.end(), 4);         // returns iterator pointing to 1st element which has value >= 4
    cout<<"The lower bound of 4: "<<p-vtr.begin()<< endl;
    auto q = upper_bound(vtr.begin(), vtr.end(), 4);         // returns iterator pointing to 1st element which has value > 4
    cout<<"The upper bound of 4: "<<q-vtr.begin()<<endl;  
    reverse(vtr.begin(),vtr.end());                          // reverse
    printVector(vtr);  
    sort(vtr.begin(),vtr.end());                             // sort
    printVector(vtr); 
    vtr.erase(vtr.begin()+3);                                // erase vtr[3]
    printVector(vtr);     
    vtr.erase(unique(vtr.begin(),vtr.end()), vtr.end());     // erase duplicate elements                     
    printVector(vtr); 
    
    
	cout<<endl<<endl<<endl;
    

    vector<int> vtr1(5, 2);                                  // vector of size=5 initialized by 2
    printVector(vtr1);
    vtr1.pop_back();     
    vector<int> *vtr2 = new vector<int>();                   // dynamic vector 
    for(int i=0; i<vtr1.size(); i++)
    vtr2->push_back(vtr1[i]);
    printDynamicVector(vtr2); 
}
  
    
    
    
    
    
 



 
