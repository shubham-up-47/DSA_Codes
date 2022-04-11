#include <bits/stdc++.h>                                     
using namespace std;

 
template <typename T>               
class TreeNode                                                                                                                            
{     public:
	T data;                                        
	vector<TreeNode<T>*> children;                  
	
	TreeNode(T d)                                                  
	{  this->data = d;  }
   
   ~TreeNode()                                      
    {  for(int i=0; i<this->children.size(); i++)
       delete this->children[i];  }	                                             
};                               
                                                                        
TreeNode<int>* storeTreeLevelWise()               
{
    int r;
	cout<<"Enter root data: ";
	cin>>r;
	
	TreeNode<int> *rp = new TreeNode<int>(r);      
	queue<TreeNode<int>*> ppList;
	ppList.push(rp);
	
	while(ppList.size() != 0)
	{
	   TreeNode<int> *pp = ppList.front();
	   ppList.pop();
	   
	   int n;
	   cout<<"Enter no of children of "<<pp->data<<": ";
	   cin>>n;
	   
	   for(int i=0; i<n; i++)                         
	   {  int c;
	      cout<<"Enter "<<i<<"th child of "<<pp->data<<": ";
	      cin>>c;
	      
	      TreeNode<int> *cp = new TreeNode<int>(c);      
	      pp->children.push_back(cp);
	      ppList.push(cp);   }	
    }
 
	return rp;
}
  
pair<TreeNode<int>*,TreeNode<int>*>   helper(TreeNode<int> *pp)            // using pair class
{
	pair<TreeNode<int>*,TreeNode<int>*> r;
	r.first = pp;                                                          // stores largest node pointer
	r.second = NULL;                                                       // stores second largest node pointer 
	 
	 
	for(int i=0; i<pp->children.size(); i++)                               // never make (rL)==(rSL) in any step bcz (largest)>(secondLargest)                    
	{   
	   pair<TreeNode<int>*,TreeNode<int>*> t = helper(pp->children[i]); 
	   
	   int tL = t.first->data;                                              // tLargest
	   int tSL = (t.second==NULL) ? INT_MIN : t.second->data;               // tSecondLargest 
	   int rL = r.first->data;                                              // rLargest
	   int rSL = (r.second==NULL) ? INT_MIN : r.second->data;               // rSecondLargest
	    
	   if(tL > rL && ((t.second==NULL) || (t.second!=NULL && rL >= tSL)))   // tLargest > rLargest > rSecondLargest         
 	   {   r.second = r.first;                   
		   r.first = t.first; 	 }             
	   else if(tL > rL && t.second!=NULL && tSL > rL)                       // tLargest > tSecondLargest > rLargest > rSecondLargest  
 	   {   r.second = t.second;
		   r.first = t.first;    }             
	   else if(rL > tL && (r.second==NULL || tL > rSL))                     // rLargest > tLargest > rSecondLargest 
	   {   r.second = t.first;   }	                     
	}
	
	                         
    return r;	
} 
 
TreeNode<int>*  secondLargestNodeOfTree(TreeNode<int> *pp)
{
	if(pp==NULL)
	return NULL;
	
	return helper(pp).second; 
}
 
int main()
{
    TreeNode<int> *rp = storeTreeLevelWise();
    cout<<endl<<endl;
    
    cout<<"Second Largest node of input tree: "<<secondLargestNodeOfTree(rp)->data; 
    cout<<endl<<endl;

    delete rp;                                                     
}                                                                                      
 
 
 /*                                                                                         
 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

            1           Level 0 
           /|\
          / | \
         2  3  4        Level 1
        /|  |\
       / |  | \
      5  6  7  8        Level 2
                \
                 \
			      9     Level 3
 */



 


