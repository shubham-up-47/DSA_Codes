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
	cout<<"L"<<pp->left->data;  
    if(pp->right != NULL)
	cout<<"R"<<pp->right->data;  
    cout<<endl; 
    
	printBST(pp->left);                                                            // printing left child tree
	printBST(pp->right);                                                           // printing right child tree
	 
	 
	return;
}	    
         
void makeSortedArrayfromBST(BinaryTreeNode<int> *pp, vector<int> &vtr)             // similar to printing Inorder  
{
    if(pp==NULL)
	return;
	                                                                                               
	makeSortedArrayfromBST(pp->left, vtr);                                                     
	vtr.push_back(pp->data);   	 
	makeSortedArrayfromBST(pp->right, vtr);	                                                               
	
	return;
}                                                              

template <typename T> 
class Node                                     
{     public:
    T data;                           
    Node *next;                            
   
    Node(T d)                        
    {  data = d;
       next = NULL;  }	 
};
           
pair<Node<int>*,Node<int>*>  makeSortedLLfromBST(BinaryTreeNode<int> *pp)          // similar to printing Inorder
{
    if(pp==NULL)
	{  pair<Node<int>*,Node<int>*>  r;
	   r.first = NULL;                                                             // first = head of LL
	   r.second = NULL;                                                            // second = tail of LL
	   return r;  }	
	
	
	Node<int> *np = new Node<int>(pp->data);
	pair<Node<int>*,Node<int>*>  r,rL,rR;
	
	if(pp->left != NULL)
	{  rL = makeSortedLLfromBST(pp->left);                                         // first make LL from lesser child
	   r.first = rL.first;
	   rL.second->next = np;  }                                               
	else
	r.first = np;
	
	if(pp->right != NULL)
	{  rR = makeSortedLLfromBST(pp->right);                                        // then make LL from greater child            
	   np->next = rR.first;
	   r.second = rR.second;  }
	else
	r.second = np;
	
	
	return r; 
}  
          
void printLL(Node<int> *head)                                                      // printing linked list                                 
{ 
    while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}
   
class infoBST
{      public:
    bool flag;                                                                     // current binary tree is BST or not
    int minN;                                                                      // min node of current binary tree
    int maxN;   };                                                                 // max node of current binary tree
    
infoBST isBST(BinaryTreeNode<int> *pp)
{
	if(pp==NULL)
	{  infoBST r{true, INT_MAX, INT_MIN};
	   return r;  }
 
 
    infoBST rL = isBST(pp->left);                          
    infoBST rR = isBST(pp->right);

    
    infoBST r;
    r.minN = min(pp->data, min(rL.minN,rR.minN));
    r.maxN = max(pp->data, max(rL.maxN,rR.maxN));
    r.flag = (pp->data > rL.maxN) & (pp->data <= rR.minN) & (rL.flag) & (rR.flag); // checking validity of (current parent) in (current BST) 
    return r;
}    
                           

vector<int>* rootToNodePath(BinaryTreeNode<int> *pp, int x)                        // root to node path for given (BT) / (BST)                             
{
    if(pp == NULL)
	return NULL;
	else if(pp->data == x)
	{  vector<int> *r = new vector<int>();
	   r->push_back(pp->data);
	   return r;  }
	            	
					   
	vector<int> *rL = rootToNodePath(pp->left, x);                            
	if(rL != NULL)   
	{  rL->push_back(pp->data);
	   return rL;  }     
	   
	vector<int> *rR = rootToNodePath(pp->right, x);
	if(rR != NULL)   
	{  rR->push_back(pp->data);
	   return rR;  }                                       
  
  
	return NULL;
}

                               
void printElementsInRangeK1K2(BinaryTreeNode<int> *pp, int k1, int k2)             // similar to printing Inorder in range [k1,k2]                     
{
	if(pp==NULL)
	return;
	
	 
	if( !(pp->data <= k1) )                                                        // if (pp->data <= k1), then no need to check on (left child BST)             
	printElementsInRangeK1K2(pp->left, k1, k2);
	
    if(pp->data >= k1 && pp->data <= k2)
	cout<<pp->data<<" ";
	
	if( !(pp->data > k2) )                                                         // if (pp->data > k2), then no need to check on (right child BST)    
	printElementsInRangeK1K2(pp->right, k1, k2);	 
	
	
	return;                                                                                                      
}

                                                                                     
int main()
{ 
	int n;
	cout<<"Enter size of sorted array: ";
	cin>>n; 
	
	int arr[n];
	cout<<"Enter elements of sorted array to make BST: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];                                                                   // storing BST 
	                  
    BinaryTreeNode<int> *rp = makeBSTfromSortedArray(arr, n);                                                                                   
	cout<<"\n\nBST constructed using sorted array"<<endl;
	printBST(rp);                                                                  // printing BST
	                                                                                 
    vector<int> vtr;
	makeSortedArrayfromBST(rp, vtr);                                                                                   
	cout<<"\nSorted array constructed using BST: ";
    for(int i=0; i<vtr.size(); i++)
    cout<<vtr[i]<<" "; 
	 
	 
	pair<Node<int>*,Node<int>*> r = makeSortedLLfromBST(rp);
	cout<<"\n\nSorted LL constructed using BST: ";
	printLL(r.first);
	 
	infoBST b = isBST(rp);
	cout<<"\nIs constructed BST a valid BST: "<<(b.flag ? "Yes\n" : "No\n")<<endl;
 
	cout<<"Root to node path for 5 in BST is: ";
	vector<int> *v = rootToNodePath(rp, 5);
    for(int i=v->size()-1; i>=0; i--)
    cout<<v->at(i)<<" "; 
	 
	cout<<"\n\nElements of BST in range [2,8] are: "; 
	printElementsInRangeK1K2(rp, 2, 8); 
	cout<<endl<<endl<<endl;
	
	
    delete rp;                                                            
}                       
           
                                                                                                    
 /*                                 
   
  6 0 2 3 5 8 13          
  
            3           Level 0 
           / \ 
          0   8         Level 1
          \  / \
          2  5 13       Level 2  
                            
 */




 // use (recursion) most of the times to solve question related to (tree), considering (current node) as (parent node) 
 
 // BST = (max node of left child BST) < (parent data) <= (min node of right child BST)
 
 // Balanced BST = (ideal BST), (O(h) = O(logn)), ( |left child BST height - right child BST height| <= 1 )
  
 // Mostly we try to access BST in sorted order (i.e. Inorder traversal of BST)                                               
 // Each time for BST, first do function call (pp->left), then access(pp->data), then do function call (pp->right)         
                                                                                    










 




