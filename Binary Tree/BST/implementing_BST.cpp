#include <bits/stdc++.h>
using namespace std;
  
 // BST(Binary Search Tree) =  (sorted Binary Tree), (inspired by Binary Search), (O(h)), (Base Case -> pp==NULL) 
 
template <typename T> 
class BinaryTreeNode                                       // class for creating a node of BST                                                                                 
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
                                                                          
class BST                                                  // class for creating a BST                      
{
	BinaryTreeNode<int> *root;
	                       
	   public:
	BST()
	{  root = NULL;	 }
	
   ~BST()
    {  delete root;  }
	
	
	   private:
	BinaryTreeNode<int>* remove(int x, BinaryTreeNode<int> *pp)
	{  
	   if(pp==NULL)
	   return pp;
	   
	   if(x < pp->data)
	   pp->left = remove(x, pp->left);
	   else if(x > pp->data)
	   pp->right = remove(x, pp->right); 
	   else                                                // removing/deleting root node of current BST
	   {  if(pp->left==NULL && pp->right==NULL)           
	   	  {  delete pp;
	   	  
	   	     pp = NULL;	 }
	   	  else if(pp->left==NULL)
	   	  {  BinaryTreeNode<int> *temp = pp->right;
	   	     pp->right = NULL;
	   	     delete pp;
	   	     
	   	     pp = temp;  }
	   	  else if(pp->right==NULL)
	   	  {  BinaryTreeNode<int> *temp = pp->left;
	   	     pp->left = NULL;
	   	     delete pp;
	   	     
	   	     pp = temp;  }
	   	  else 
	   	  {  BinaryTreeNode<int> *temp = pp->right;
	   	  
	   	     while(temp->left != NULL)
	   	     temp = temp->left;
	   	     
	   	     int rightBST_min = temp->data;
	   	     pp->data = rightBST_min;                      // making min element of right child BST as new root
	   	   
	   	     pp->right = remove(rightBST_min, pp->right);  }   } 
	   	     
	   return pp;	     
	} 
	                                                                                                        
	bool search(int x, BinaryTreeNode<int> *pp)
	{
	   if(pp==NULL)
	   return 0;   
	   
	   if(pp->data == x)
	   return 1;
	   else if(x > pp->data)
	   return search(x, pp->right);
	   if(x < pp->data)
	   return search(x, pp->left);
	   
	   return 0;
	}
	
    void print(BinaryTreeNode<int> *pp)                    // printing BST parent wise
    {                                
       if(pp==NULL)
       return;
	 
 	   cout<<pp->data<<":";                                // print parent 
       if(pp->left != NULL)
	   cout<<"L"<<pp->left->data;  
       if(pp->right != NULL)
	   cout<<"R"<<pp->right->data;  
       cout<<endl; 
	   print(pp->left);                                    // printing left child tree
	   print(pp->right);                                   // printing right child tree
	 
	   return;
    }	       
	
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
	
	    public:                // pp is not a input in these function, so create private helper functions, to apply recursion 
	void remove(int x)
	{  root = remove(x, root);	}
	
	bool search(int x)
	{  return search(x, root);  }
	
	void print()
	{  print(root);  }
		
    void insert(int x)
    {  root = insert(x, root);  } 
};

                  
int main()
{
	BST b;                                                 // constructing BST using (BST class) & (BinaryTreeNode class)
	
	
	int n;
	cout<<"Enter size of BST: ";
	cin>>n; 
	
	cout<<"Enter elements of BST: ";
    for(int i=0; i<n; i++)
    {  int x;
	   cin>>x;
	   b.insert(x);  }                                     // storing BST 
	
	cout<<"\nBST constructed using input data"<<endl;
	b.print();                                             // printing BST
	 
	cout<<"\nIs 7 present in BST: "<<(b.search(7) ? "Yes\n" : "No\n")<<endl;
	 
	b.remove(4);
	cout<<"BST after removing 4"<<endl;
	b.print();
	 
	 
    delete &b;                                             // deleting BST                   
}
                                                                         
                                                                                                  
 /*
 
[ Type of BST constructed by above function, depends on input array ]                                   
 
  4 2 5 1 3 6          
            4           Level 0 
           / \ 
          2   5         Level 1
         /\    \
        1  3    6       Level 2  
			 
			 
  1 2 3 4 5 6  
      1                 Level 0 
       \
        2               Level 1 
         \
          3             Level 2 
           \ 
            4           Level 3
             \
              5         Level 4
               \
                6       Level 5     
				                                            
 */




 // use (recursion) most of the times to solve question related to (tree), considering (current node) as (parent node) 
 
 // BST = (left child data) < (parent data) <= (right child data)
 
 // Balanced BST = (ideal BST), (O(h) = O(logn)), ( |left child BST height - right child BST height| <= 1 )
  
 // (r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   


                                                        

                                                                                    






 





