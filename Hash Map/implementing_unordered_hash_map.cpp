#include <bits/stdc++.h>
using namespace std;

 // Unordered Hash Map = (Table of (Key,Value)), (O(1)), (unordered_map<d1, d2>), (default Value of new Key is 0)                                            
  
template <typename V>
class MapNode                                                                  // class of a node, of LL (whose head is stored in BucketArray)               
{         public:
	string key;                                                                // key (string)
	V value;                                                                   // value (template)
	MapNode *next;                                                             // address of next node
	
	MapNode(string k, V v)                                                     // constructor
	{  key = k;
	   value = v;
	   next = NULL;  }
	
   ~MapNode()                                                                  // distructor
    {  delete next;	 }	
};


template <typename V>
class ourmap                                                                   // class of HashMap 
{ 
    MapNode<V> **buckets;                                                      // base address of BucketArray (storing addresses of LL heads)
    int count;                                                                 // no of LL nodes (which store (Key,Value) data)
    int numBuckets;                                                            // capacity of BucketArray
   
          public:
    ourmap()                                                                   // constructor
    {  count = 0;
       numBuckets = 5;
 
	   buckets = new MapNode<V>*[numBuckets];                                  // BucketArray (array in which addresses of LL heads are stored)
	   for(int i=0; i<numBuckets; i++)
	   buckets[i] = NULL;  }
	   
   ~ourmap()                                                                   // distructor
	{  for(int i=0; i<numBuckets; i++)
	   buckets[i] = NULL;
	  	
	   delete [] buckets;  } 
	                                             
    int size()                                                                 // no of LL nodes (which store (Key,Value) data)
	{  return count;  }	
	
	V getValue(string k)                                                       // search function
	{  
	   int i = getBucketIndex(k);                                              // getting indexNumber (in BucketArray) for LL of inputKey 
	
	   for(MapNode<V> *currN=buckets[i]; currN!=NULL; currN=currN->next)       // travelling on LL
	   {  if(currN->key==k)
	      return currN->value;  }
		
	   return 0;   
	}                                                                                   
	
	      private:
	void compress(int &n)                                                      // compression function (gives output in range (0) to (BucketSize-1))                                  
	{  n = n % numBuckets;  }
	
	int getBucketIndex(string key)                                             // (hash function = HashCode + CompressionFunction) (Key to indexNo)                              
	{  
	   int N=0, p=1;
	
	   for(int i=key.size()-1; i>=0; i--)                                      // hash code ( N = AV*(p^3) + AV*(p^2) + AV*(p^1) + AV*(p^0) ) 
	   {  N += key[i]*p;                                                       // AV = ASCII Value = key[i]
	      compress(N);                                                         // compression
	       
	      p = p*37;                                                            // compression
	      compress(p);  }
		
	   return N;   
	}
	                           
	void rehash()                                                              //  rehashing function (double BucketArray capacity)
	{  
	   MapNode<V> **oldBucket = buckets;
	   int oldBucketSize = numBuckets;
		
		
	   numBuckets *= 2;                                                        // doubling bucket size
	   buckets = new MapNode<V>*[numBuckets];
	   for(int i=0; i<numBuckets; i++)
	   buckets[i] = NULL;
	   count = 0;                                                              // important step***
	   
	   for(int i=0; i<oldBucketSize; i++)                                      // inserting each (Key,Value) nodes of old BucketArray in BucketArray
	   {   for(MapNode<V> *currN=oldBucket[i]; currN!=NULL; currN=currN->next)
	       insert(currN->key, currN->value);   }   	
	
		
	   for(int i=0; i<oldBucketSize; i++)                                      // deleting old BucketArray & its LinkedLists
	   {   MapNode<V> *head = oldBucket[i];
	       delete head;   }	 
	   delete [] oldBucket;	                                              
    }
	
	       public:
	void insert(string k, V v)                                                 // insert function                        
	{
	   int i = getBucketIndex(k);                                              // getting indexNumber (in BucketArray) for LL of inputKey 
	   
	   for(MapNode<V> *currN=buckets[i]; currN!=NULL; currN=currN->next)
	   {   if(currN->key==k)                                                   // if given (Key) is already present then update (Value)
	       {  currN->value = v;
	          return;   }	}  	
		
	   MapNode<V> *np = new MapNode<V>(k,v);                                   // else store (Key,Value) in a new node (Seperate Chaining)                 
	   np->next = buckets[i];
	   buckets[i] = np;
	   count++;	
		
	   if(getLoadFactor() > 0.7)                                               // when n/b > 0.7, do rehashing, so that HashMap can maintain O(1) 
	   rehash();                                                               // (n = no of entries) & (b = capacity of BucketArray) 
	}
	
	double getLoadFactor()                                                     // function to get Load Factor
	{  return (1.0*count)/numBuckets;  }
	 	 
	V remove(string k)                                                         // delete function
	{  int i = getBucketIndex(k);
	
	   for(MapNode<V> *preN=NULL,*currN=buckets[i];  currN!=NULL;  preN=currN,currN=currN->next)
	   {   if(currN->key==k)
	       {  if(preN==NULL)                                                   // if (Key,Value) node is head node                 
		      buckets[i] = currN->next;
			  else                                                             // if (Key,Value) node is middle node   
			  preN->next = currN->next;
			  
			  V r = currN->value;
			  currN->next = NULL;
			  delete currN;
			  count--;
			  return r;	 }   }
			  
	   return 0;		                                                                                        
    }
};
 
 
int main()                                                                     
{                                                                              // (Key,Value) = (string,int)
	ourmap<int>  h;                                                            // datatype of (Key) is already decided so pass datatype of (Value)
		  
	cout<<"Change in Load Factor values (while inserting elements 1 by 1): "<<endl;
	for(int i=0; i<10; i++)
	{  char c = '0' + i;
	   string key = "abc";
	   key = key + c;
	   
	   int value = i+1;
	   h.insert(key,value);                                                    // insert
		
	   cout<<h.getLoadFactor()<<"  ";   }
	   
	cout<<endl<<"\n\nCurrent size of Unordered hash map: "<<h.size()<<endl;    // size
	h.remove("abc2");                                                          // delete
	h.remove("abc7");
	cout<<"Current size of Unordered hash map: "<<h.size()<<endl;
	
	
	cout<<"\n\nUnordered hash map elements are: \n";                           // printing map 
	cout<<"[Key]  [Value]\n"; 
	for(int i=0; i<10; i++)                                                    
	{  char c = '0' + i;
	   string key = "abc";
	   key = key + c;
	   
	   int value = i+1; 
	   cout<<" "<<key<<" : "<<h.getValue(key)<<endl;  }                        // search  

    cout<<"\n[(Value=0) will be returned, if the (Key) is not present in HashMap]"<<endl;
	cout<<"\n\nCurrent size of Unordered hash map: "<<h.size()<<endl<<endl; 
}


 
/* 

   [Key]   [Value] 
   abc0       1
   abc1       2   
   abc2       3
   abc3       4
   abc4       5
   abc5       6
   abc6       7
   abc7       8
   abc8       9
   abc9       10
 
*/



/* 
    ->  Unordered Hash Map { O(1) }
*it doesn't allow duplicate keys & default value of new key is 0   
*implemented using Hash Table conept                                  
*it's each node stores (Key,Value)                                           
*datatype of Key & Value is decided by us
*highly optimized datastructure but data stored in it is unordered 
*code of HashMapClass depends on datatype of Key 
*(Value=0) will be returned, if the (Key) is not present in HashMap
  
*/



// (V=templateDatatype), (k=Key), (v=Value), (p=primeFactor), (N=noGeneratedUsingHashFunctionOfKey), (np=nodePointer) 













