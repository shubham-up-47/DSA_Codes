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
                                                                                         
BinaryTreeNode<int>* storeBTLevelWise()               
{
    int r;
	cout<<"Enter root data: ";
	cin>>r;
	
	if(r==-1)                                              // typing -1 for (left child) & (right child) means (parent node = leaf node)
	return NULL;
	                                       
	BinaryTreeNode<int> *rp = new BinaryTreeNode<int>(r);  // making parent/current node dynamically ( T = int )

	queue<BinaryTreeNode<int>*> ppList;                    // queue storing pp level wise 
	ppList.push(rp); 
	while(ppList.size() != 0)    // for all parent at a specific level, store all child pointer in (queue) after (connecting with parent) 
	{
	   BinaryTreeNode<int> *pp = ppList.front();           // current pp        
	   ppList.pop();
	                                                                                             
	   int l_c;                               
	   cout<<"Left child of "<<pp->data<<": ";
	   cin>>l_c;             
	   if(l_c != -1)                        
	   {  BinaryTreeNode<int> *l_cp = new BinaryTreeNode<int>(l_c);    
	      pp->left = l_cp;                                 // connecting left child 
	      ppList.push(l_cp);   }	                         
 
	   int r_c;                               
	   cout<<"Right child of "<<pp->data<<": ";
	   cin>>r_c;          
	   if(r_c != -1)                        
	   {  BinaryTreeNode<int> *r_cp = new BinaryTreeNode<int>(r_c);    
	      pp->right = r_cp;                                // connecting right child 
	      ppList.push(r_cp);   }                                                   
    } 
 
	return rp;
}

void printBTLevelWise(BinaryTreeNode<int> *rp)
{                                
    if(rp==NULL)
	return;
	
	queue<BinaryTreeNode<int>*> ppList;                         
	ppList.push(rp);
	
	while(ppList.size() != 0)   // for all parent at a specific level, print the children & store all child pointer in (queue) 
	{
	   BinaryTreeNode<int> *pp = ppList.front();           // printing current parent
	   ppList.pop(); 
	   
	   cout<<pp->data<<": ";
	   
	   if(pp->left != NULL)        
	   {  cout<<"L"<<pp->left->data;                       // printing left child   
	      ppList.push(pp->left);  } 
	   if(pp->right != NULL)        
	   {  cout<<"R"<<pp->right->data;                      // printing right child          
	      ppList.push(pp->right);  } 
	      
	   cout<<endl;
    }
}	                                                             
                               
          
int main()
{
    BinaryTreeNode<int> *rp = storeBTLevelWise();          // iterative
    cout<<endl<<endl;
    
    cout<<"Printing binary tree level wise\n";
    printBTLevelWise(rp);                                  // iterative
    cout<<endl<<endl;
 
    delete rp;                                             // user defined distructor called (deletes complete tree)                
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


 // use (recursion) most of the times to solve question related to (tree) considering (current node) as (parent node) 
 // Genric Tree = each parent can have any no of children   (Base Case -> pp->children.size()==0)
 // Binary Tree = each parent can have 0 / 1 / 2 children   (Base Case -> pp==NULL) 
 // (r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   












 
