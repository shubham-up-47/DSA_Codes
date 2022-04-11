#include <bits/stdc++.h>                                
using namespace std;                                               
  
 // BST(Binary Search Tree) =  (sorted Binary Tree), (inspired by Binary Search), (O(h)), (Base Case -> pp==NULL) 
 
template <typename T> 
class BinaryTreeNode                                                               // class for creating a node of BST                                                                                 
{      public:
	T data;                                            
	BinaryTreeNode *left;                     
	BinaryTreeNode *right;                         
 
	BinaryTreeNode(T d)                                  
	{  data = d;
	   left = NULL;
	   right = NULL;  } 
	   
   ~BinaryTreeNode()                                      
    {  delete left;
       delete right;  }
};     
                                            
BinaryTreeNode<int>* makeBSTfromSortedArray(int *arr, int n)                       // using concept of merge sort         
{ 
    if(n==0)
    return NULL;


	int si = 0;
	int ei = n-1; 
	int mid = (si+ei)/2;                  
	                                        
	BinaryTreeNode<int> *pp = new BinaryTreeNode<int>(arr[mid]); 
	                                                          
	pp->left = makeBSTfromSortedArray(arr, mid);  
	pp->right = makeBSTfromSortedArray(arr+mid+1, ei-mid);	 
	
	
	return pp;
}                                
 
void printBST(BinaryTreeNode<int> *pp)                                             // printing BST parent wise
{                                
    if(pp==NULL)
    return;
	                                                                                      
	 
 	cout<<pp->data<<":";                                                           // print parent 
    if(pp->left != NULL)
	cout<<" L"<<pp->left->data;  
    if(pp->right != NULL)
	cout<<" R"<<pp->right->data;  
    cout<<endl; 
    
	printBST(pp->left);                                                            // printing left child tree
	printBST(pp->right);                                                           // printing right child tree
	 
	 
	return;
}	    
          
int helper(BinaryTreeNode<int> *pp, int sum)                                       // sum value of greater nodes (from parent BST)
{
	if(pp==NULL)                                            
    return 0;
	  
	int sumR = helper(pp->right, sum);                                             // sum value of greater nodes (from right child BST) 
	pp->data += sum + sumR;
	int sumL = helper(pp->left, pp->data);
	                                           
	return (pp->data + sumL - sum); 	                                           // sum of BST data (in this subtree only)      
}

void replaceNodeByAddingGreaterNodes(BinaryTreeNode<int> *pp)
{
	if(pp==NULL)
	return;
 	                               
	int sumR = helper(pp->right, 0);                                               // sum of right child BST data
	pp->data += 0 + sumR; 
	int sumL = helper(pp->left, pp->data);                                         // sum of left child BST data
}    
           
		                                                                                                               
int main()
{ 
	int n;
	cout<<"Enter size of sorted array: ";
	cin>>n; 
	
	int arr[n];
	cout<<"Enter sorted array to make BST: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];                                                                   // storing BST 
	                  
    BinaryTreeNode<int> *rp = makeBSTfromSortedArray(arr, n);                                                                                   
	cout<<"\n\nBST constructed using sorted array"<<endl;
	printBST(rp);                                                                  // printing BST
	                                                                                 
    replaceNodeByAddingGreaterNodes(rp); 
	cout<<"\n\nBST after replacing node by sum of greater nodes"<<endl;
	printBST(rp);
	
    delete rp;                                                            
}      
                            
                                                                                                                   
 /*                                 
   
  6    0 2 3 5 8 13          
  
            3           Level 0 
           / \ 
          0   8         Level 1
          \  / \
          2  5 13       Level 2  
                            
 */
 







 

