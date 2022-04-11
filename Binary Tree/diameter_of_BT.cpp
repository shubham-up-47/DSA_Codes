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

 // diameter of BT: max distance between any 2 nodes of Binary Tree                                           
     
pair<int,int> diameterOfBT(BinaryTreeNode<int> *pp)   
{
    if(pp==NULL)
	{  pair<int,int> r;                                // maintaining pair class in recursion calls
	   r.first = 0;                                    // r.first = height of BT
	   r.second = 0;                                   // r.second = diameter of BT
	   return r;  }
   
   
	pair<int,int> rL = diameterOfBT(pp->left);	 
	pair<int,int> rR = diameterOfBT(pp->right);	 
	int hL = rL.first;                                 // height of left child BT
	int dL = rL.second;                                // diameter of left child BT    
	int hR = rR.first;                                 // height of right child BT
	int dR = rR.second;	                               // diameter of right child BT   	
	 
	 
	pair<int,int> r;                 
	r.first = 1 + max(hL, hR);                         // height of parent BT 
	r.second = max(hL+hR, max(dL,dR));                 // diameter of parent BT 
	return r;
}                                                                               
       
                                  
int main()
{ 
    BinaryTreeNode<int> *rp = storeBTLevelWise();  
     
    pair<int,int> r = diameterOfBT(rp);	
	cout<<"\n\n\nHeight of binary tree: "<<r.first<<endl<<endl;  
	cout<<"Diameter of binary tree: "<<r.second<<endl<<endl;              
 
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
 













