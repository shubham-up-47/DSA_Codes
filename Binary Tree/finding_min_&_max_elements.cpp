#include <bits/stdc++.h>
using namespace std;
   
   
template <typename T> 
class BinaryTreeNode                                                                                                                  
{      public:
	T data;                                        
	BinaryTreeNode *left;                                
	BinaryTreeNode *right;                            
 
	BinaryTreeNode(T d)                               
	{  data = d;
	   left = NULL;
	   right = NULL;   } 
	   
   ~BinaryTreeNode()                                
    {  delete left;
       delete right;   }
};     
                                                                                         
BinaryTreeNode<int>* storeBTLevelWise()               
{
    int r;
	cout<<"Enter root data: ";
	cin>>r;
	
	if(r==-1)                                               
	return NULL;
	                                       
	BinaryTreeNode<int> *rp = new BinaryTreeNode<int>(r);  

	queue<BinaryTreeNode<int>*> ppList;                  
	ppList.push(rp); 
	while(ppList.size() != 0)          
	{
	   BinaryTreeNode<int> *pp = ppList.front();         
	   ppList.pop();
	   
	   int l_c;                               
	   cout<<"Left child of "<<pp->data<<": ";
	   cin>>l_c;             
	   if(l_c != -1)                        
	   {  BinaryTreeNode<int> *l_cp = new BinaryTreeNode<int>(l_c);    
	      pp->left = l_cp;                             
	      ppList.push(l_cp);   }	                         
 
	   int r_c;                               
	   cout<<"Right child of "<<pp->data<<": ";
	   cin>>r_c;          
	   if(r_c != -1)                        
	   {  BinaryTreeNode<int> *r_cp = new BinaryTreeNode<int>(r_c);    
	      pp->right = r_cp;                             
	      ppList.push(r_cp);   }                                                   
    } 
 
	return rp;
}
     
pair<int,int> find_Min_Max_Elements(BinaryTreeNode<int> *pp) 
{
    if(pp==NULL)
	{  pair<int,int> r;                                          // maintaining pair class in recursion calls
	   r.first = INT_MAX;                                        // r.first = min element value
	   r.second = INT_MIN;                                       // r.second = max element value
	   return r;  }
   
	pair<int,int> r1 = find_Min_Max_Elements(pp->left);	 
	pair<int,int> r2 = find_Min_Max_Elements(pp->right);	 
	
	pair<int,int> r;	
	r.first = min(pp->data, min(r1.first,r2.first));
	r.second = max(pp->data, max(r1.second,r2.second));
	return r;
}                                                                               
       
       
int main()
{ 
    BinaryTreeNode<int> *rp = storeBTLevelWise();  
     
    pair<int,int> r = find_Min_Max_Elements(rp);	
	cout<<"\n\nMin element of Binary tree: "<<r.first; 
	cout<<"\n\nMax element of Binary tree: "<<r.second;              
 
    delete rp;                                                     
}
             
 /*
 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1                      

            1           Level 0 
           / \ 
          2   3         Level 1
         /\   /\
        4  5 6  7       Level 2 
          /\
         8  9           Level 3                                                  
 */
 











