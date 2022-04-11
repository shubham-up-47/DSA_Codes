#include <bits/stdc++.h>
using namespace std;
  
 // BST(Binary Search Tree) =  (sorted Binary Tree), (inspired by Binary Search), (O(h)), (Base Case -> pp==NULL) 
 
template <typename T> 
class BinaryTreeNode                                                    // class for creating a node of BST                                                                                 
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
                                                                          
class BST                                                               // class for creating a BST                      
{
	BinaryTreeNode<int> *root;
	                       
	   public:
	BST()
	{  root = NULL;	 }
	
   ~BST()
    {  delete root;  }
	
	
	   private:
	BinaryTreeNode<int>* insert(int x, BinaryTreeNode<int> *pp)
    {
   	   if(pp==NULL)
	   {  BinaryTreeNode<int> *np = new BinaryTreeNode<int>(x);
	      return np;  }   
	   
	   if(x < pp->data)
	   pp->left = insert(x, pp->left);
	   else if(x >= pp->data)
	   pp->right = insert(x, pp->right); 
	   
	   return pp;
	}	
	
	    public:                            // pp is not a input in these function, so create private helper functions, to apply recursion 
	BinaryTreeNode<int>* findRoot()
	{  return root;  }
		
    void insert(int x)
    {  root = insert(x, root);  } 
};

void print_KdistanceDown_nodes(BinaryTreeNode<int> *pp, int k)          // printing nodes who are K distance down from Target node
{
	if(pp==NULL || k<0)
	return;
	else if(k==0)
	{  cout<<pp->data<<" ";
       return;	}
        
        
	print_KdistanceDown_nodes(pp->left, k-1);
	print_KdistanceDown_nodes(pp->right, k-1);
	 
	 
	return; 
}
          
void print_KdistanceUp_nodes(BinaryTreeNode<int> *pp, stack<BinaryTreeNode<int>*> s, int k)  
{                                                                       // printing nodes who are K distance up from Target node
	if(pp==NULL || k<0)
	return;
	else if(k==0)
	{  cout<<pp->data<<" ";
       return;	} 
	else if(s.size()==0)
	return;
	                 
	
	BinaryTreeNode<int> *pp_T= s.top();                                 // parent of Target node
	s.pop();
	  
	print_KdistanceUp_nodes(pp_T, s, k-1);                              // printing nodes who are (K-1) distance up from parent of Target node
	
	if(pp_T->left != pp)                                                // printing nodes who are (K-2) distance down from sibling of Target node 
	print_KdistanceDown_nodes(pp_T->left, k-2); 
	else if(pp_T->right != pp)
	print_KdistanceDown_nodes(pp_T->right, k-2); 
	
	 
	return; 
}
         
void reachToTargetNode(BinaryTreeNode<int> *pp, stack<BinaryTreeNode<int>*> s, int x, int k)     
{ 
	if(pp==NULL)
	return;
	else if(pp->data==x)
	{  print_KdistanceUp_nodes(pp, s, k);
	   print_KdistanceDown_nodes(pp, k);
	   return;  }
	 
	 
	s.push(pp);                                                         // keep memory of path travelling from root to Target node
	reachToTargetNode(pp->left, s, x, k); 
	reachToTargetNode(pp->right, s, x, k);
  
  
	return; 
}
         
void print_Kdistance_nodes(BinaryTreeNode<int> *rp, int x, int k)
{
	stack<BinaryTreeNode<int>*> s;                                      // keep memory of path travelling from root to Target node
	reachToTargetNode(rp, s, x, k);                                     // first reach to Target node from root   
}
                      
                      
int main()
{
	BST bst;                                                            // constructing BST using (BST class) & (BinaryTreeNode class)
	
	 
	int n;
	cout<<"Enter size of BST: ";
	cin>>n; 
	
	cout<<"Enter elements of BST: ";
    for(int i=0; i<n; i++)
    {  int x;
	   cin>>x;
	   bst.insert(x);  }                                                // storing BST 
	
	int x, k;
	cout<<"Enter Target node & K value: ";
	cin>>x>>k; 
	BinaryTreeNode<int> *rp = bst.findRoot();
	cout<<"\n\nNodes having distance K="<<k<<" from "<<x<<" are: ";
	print_Kdistance_nodes(rp, x, k);
	cout<<endl<<endl;                  
 
	 
    delete &bst;                                                        // deleting BST                   
}
                                                                                                   
 /*
  
   9   4 2 6 1 3 5 8 7 9    5 3     
        
            4           Level 0 
           / \ 
          2   6         Level 1
         /\   /\
        1  3 5  8       Level 2    
                /\
               7  9     Level 3
				                                            
 */





 // use (recursion) most of the times to solve question related to (tree), considering (current node) as (parent node) 
 
 // BST = (left child data) < (parent data) <= (right child data)
 
 // Balanced BST = (ideal BST), (O(h) = O(logn)), ( |left child BST height - right child BST height| <= 1 )
  
 // (r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   


                                                        











