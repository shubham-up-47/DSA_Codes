#include <bits/stdc++.h>
using namespace std;

// STORING & PRINTING BT(BINARY TREE) PARENT WISE                                       

template <typename T> 
class BinaryTreeNode                                       // BT (Binary Tree)                                                                                 
{      public:
	T data;                                                // data of parent/current node (p)
	BinaryTreeNode *left;                                  // left child pointer (l_cp)   
	BinaryTreeNode *right;                                 // right child pointer (r_cp)
 
	BinaryTreeNode(T d)                                    // constructor
	{  data = d;
	   left = NULL;
	   right = NULL;   } 
	   
   ~BinaryTreeNode()                                       // distructor
    {  delete left;
       delete right;   }
};     
                                                                                                                                         
BinaryTreeNode<int>* storeBTparentWise()                       
{
    int p;
	cout<<"Enter data: ";
	cin>>p;
	
	if(p==-1)                                              // typing -1 for (left child) & (right child) means (parent node = leaf node)
	return NULL;
	  
	BinaryTreeNode<int> *pp = new BinaryTreeNode<int>(p);  // making parent/current node dynamically ( T = int )
    BinaryTreeNode<int> *l_cp = storeBTparentWise();
	BinaryTreeNode<int> *r_cp = storeBTparentWise();                                                                                        
    pp->left = l_cp;
    pp->right = r_cp;
  
	return pp;
}
                                                           
void printBTparentWise(BinaryTreeNode<int> *pp)
{                                
    if(pp==NULL)
	return;
	
	
	cout<<pp->data<<":";                                   // print parent 
    if(pp->left != NULL)
	cout<<"L"<<pp->left->data;  
    if(pp->right != NULL)
	cout<<"R"<<pp->right->data;  
    cout<<endl;
    
	printBTparentWise(pp->left);                           // printing left child tree
	printBTparentWise(pp->right);                          // printing right child tree
	
	
	return;
}	                   
               
			                                                                                                                                                           
int main()
{
    BinaryTreeNode<int> *rp = storeBTparentWise();         // recursive
    cout<<endl<<endl;
    
    cout<<"Printing binary tree parent wise\n";
    printBTparentWise(rp);                                 // recursive
    cout<<endl;
    
    delete rp;                                             // distructor of BinaryTreeNode class is called           
}
  
                                           
 /*
 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1                                             

            1           Level 0 
           / \
          /   \
         2     3        Level 1
        /|     |\
       / |     | \
      4  5     6  7     Level 2 
 */


 // use (recursion) most of the times to solve question related to (tree) considering (current node) as (parent node)   
 // Genric Tree = each parent can have any no of children   (Base Case -> pp->children.size()==0)
 // Binary Tree = each parent can have 0 / 1 / 2 children   (Base Case -> pp==NULL) 
 // (r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   



























