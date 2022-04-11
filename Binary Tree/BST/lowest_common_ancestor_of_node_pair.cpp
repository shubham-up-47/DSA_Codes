#include <bits/stdc++.h>
using namespace std;
  
 // BST(Binary Search Tree) =  (sorted Binary Tree), (inspired by Binary Search), (O(h)), (Base Case -> pp==NULL) 
 
template <typename T> 
class BinaryTreeNode                                                             // class for creating a node of BST                                                                                 
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
                                                                          
class BST                                                                        // class for creating a BST                      
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
	 
	    public:                  // pp is not a input in these function, so create private helper functions, to apply recursion 
	BinaryTreeNode<int>* findRoot()
	{  return root;  }
		
    void insert(int x)
    {  root = insert(x, root);  }  
};

int lowestCommonAncestor(BinaryTreeNode<int> *pp, int a, int b)                                                  
{
	if(pp==NULL)
	return -1;
	else if(pp->data==a || pp->data==b)
	return pp->data;
	
	                
	int rL = lowestCommonAncestor(pp->left, a, b);                               // searching LCS of (a,b) in (left child BST)     
	if(rL!=-1 && rL!=a && rL!=b)
	return rL;                  

    int rR = lowestCommonAncestor(pp->right, a, b);                              // searching LCS of (a,b) in (right child BST)       
	if(rR!=-1 && rR!=a && rR!=b)
	return rR;
	
	
	if((rL==a && rR==b) || (rL==b && rR==a))                                     // lowest common ancestor found (a & b both found in current BST)
	return pp->data;
	else if((rL==a||rL==b) && rR==-1)                                            // (a/b is found in left child BST)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	return rL;                                      
	else if(rL==-1 && (rR==a||rR==b))                                            // (a/b is found in right child BST)  
	return rR;
    else if(rL==-1 && rR==-1)                                                    // (Neither a nor b is found in current BST)
	return -1;                                                                  
}
        
  
int main()
{
	BST bst;                                                                     // constructing BST using (BST class) & (BinaryTreeNode class)
	
	 
	int n;
	cout<<"Enter size of BST: ";
	cin>>n; 
	
	cout<<"Enter elements of BST: ";
    for(int i=0; i<n; i++)
    {  int x;
	   cin>>x;
	   bst.insert(x);  }                                                         // storing BST 
 
	int a, b;
	cout<<"Enter node pair: ";
	cin>>a>>b; 
	BinaryTreeNode<int> *rp = bst.findRoot();
	cout<<"\n\nLowest common ancestor of node pair "<<a<<" & "<<b<<" is: ";
	cout<<lowestCommonAncestor(rp, a, b)<<endl<<endl;                  
 
	 
    delete &bst;                                                                 // deleting BST                   
}
                                                                         
                                                                                                  
 /*
  
 9   4 2 6 1 3 5 8 7 9    5 7           
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


                                                        

        
        
        
        
        
        
        



