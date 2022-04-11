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
  
void printBTLevelWise(BinaryTreeNode<int> *rp)
{                                
    if(rp==NULL)
	return;
	
	queue<BinaryTreeNode<int>*> ppList;                         
	ppList.push(rp);
	
	while(ppList.size() != 0)              
	{
	   BinaryTreeNode<int> *pp = ppList.front();              
	   ppList.pop(); 
	   cout<<pp->data<<": ";
	   
	   if(pp->left != NULL)        
	   {  cout<<"L"<<pp->left->data;                         
	      ppList.push(pp->left);  } 
	   if(pp->right != NULL)        
	   {  cout<<"R"<<pp->right->data;                            
	      ppList.push(pp->right);  } 
	   cout<<endl;
    }
}	  

 // Preorder = [root] [left child tree] [right child tree]
   
 // Inorder = [left child tree] [root] [right child tree]   
   
 // Postorder = [left child tree] [right child tree] [root]                     
   
 // n = size of BT = size of Preorder = size of Inorder = size of Postorder  
 // nL = size of left child BT 
 // nR = size of right child BT 
               
BinaryTreeNode<int>* generatingBTusingPreorderInorder(int *Preorder, int *Inorder, int n)   // Preorder, Inorder & size of (current BT)
{
    if(n==0)
	return NULL;                                           
	                                             
	
	int r = Preorder[0];                                  
	BinaryTreeNode<int> *rp = new BinaryTreeNode<int>(r);                                   // creating root of (current BT) 
	
	int nL=0, nR=n-1;                                                                       // calculating size of (left child BT) & (right child BT)
	while(Inorder[nL] != r)                                                                 // considering root element is unique 
	nL++,nR--; 
	                 
	rp->left = generatingBTusingPreorderInorder(Preorder+1, Inorder, nL);                   // Preorder, Inorder & size of (left child BT)
	rp->right = generatingBTusingPreorderInorder(Preorder+1+nL, Inorder+nL+1, nR);          // Preorder, Inorder & size of (right child BT)					 
 
 
	return rp;
}                                                      
                   
BinaryTreeNode<int>* generatingBTusingInorderPostorder(int *Inorder, int *Postorder, int n) // Inorder, Postorder & size of (current BT)
{
    if(n==0)
	return NULL;                                           
	                                             
	
	int r = Postorder[n-1];                                  
	BinaryTreeNode<int> *rp = new BinaryTreeNode<int>(r);                                   // creating root of (current BT) 
	
	int nL=0, nR=n-1;                                                                       // calculating size of (left child BT) & (right child BT)
	while(Inorder[nL] != r)                                                                 // considering root element is unique 
	nL++,nR--; 
	                 
	rp->left = generatingBTusingInorderPostorder(Inorder, Postorder, nL);                   // Inorder, Postorder & size of (left child BT)
	rp->right = generatingBTusingInorderPostorder(Inorder+nL+1, Postorder+nL, nR);          // Inorder, Postorder & size of (right child BT)					 
 
 
	return rp;
}       

int* takeInput(int n)
{
   int *arr = new int[n];	
   
   for(int i=0; i<n; i++)
   cin>>arr[i];  
   
   return arr; 
}                                               
             
int main()
{  
    int n; 
	cout<<"Enter size of BT: ";
	cin>>n;
	
	cout<<"Enter Preorder of BT: ";
    int *Preorder = takeInput(n);  
	cout<<"Enter Inorder of BT: ";
    int *Inorder = takeInput(n);
	cout<<"Enter Postorder of BT: ";
    int *Postorder = takeInput(n);
	  
	  
	BinaryTreeNode<int> *rp1 = generatingBTusingPreorderInorder(Preorder, Inorder, n);
	cout<<"\n\nBT generated using Preorder & Inorder\n";
    printBTLevelWise(rp1); 
    delete rp1;
    
	BinaryTreeNode<int> *rp2 = generatingBTusingInorderPostorder(Inorder, Postorder, n);
 	cout<<"\nBT generated using Inorder & Postorder\n";
    printBTLevelWise(rp1);  
	delete rp2;                                                     
}                                          
                            
 
/*
                                                                                                                                     
 9 1 2 4 5 8 9 3 6 7 4 2 8 5 9 1 6 3 7 4 8 9 5 2 6 7 3 1                       

            1           Level 0 
           / \ 
          2   3         Level 1
         /\   /\
        4  5 6  7       Level 2 
          /\
         8  9           Level 3       
         
 Size: 9		 
 PreOrder: 1 2 4 5 8 9 3 6 7
 InOrder: 4 2 8 5 9 1 6 3 7
 PostOrder: 4 8 9 5 2 6 7 3 1                                             
 
*/
                                                                                                                                                 










 

