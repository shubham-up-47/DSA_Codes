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
 
int totalNodes(BinaryTreeNode<int> *pp)
{
	if(pp==NULL)
	return 0;
	 
	int count = 1 + totalNodes(pp->left) + totalNodes(pp->right);               
	
	return count; 
}
 
int getHeight(BinaryTreeNode<int> *pp)                        // height = no of levels
{
	if(pp==NULL)
	return 0;
	
	int h1 = getHeight(pp->left);                             // height of left child tree  
	int h2 = getHeight(pp->right);                            // height of right child tree 
	
	return (1 + max(h1,h2));                                  // overall height   
}

bool isNodePresent(BinaryTreeNode<int> *pp, int x)                   
{
	if(pp==NULL)
	return 0;
	else if(pp->data==x)                      
	return 1;
	                                                                                      
	bool b1 = isNodePresent(pp->left, x);
	bool b2 = isNodePresent(pp->right, x);               
 
	return b1|b2; 
}
                     
void printPreOrder(BinaryTreeNode<int> *pp)                   // prints (parent)->(left child)->(right child)  
{
    if(pp==NULL)
	return;
	
	cout<<pp->data<<" ";                                 
	printPreOrder(pp->left);	 
	printPreOrder(pp->right);	 
		
	return;
}

void printPostOrder(BinaryTreeNode<int> *pp)                  // prints (left child)->(right child)->(parent)   
{
    if(pp==NULL)
	return;
	                         
	printPostOrder(pp->left);	 
	printPostOrder(pp->right);	 
	cout<<pp->data<<" ";    
	
	return;
}

void printInOrder(BinaryTreeNode<int> *pp)                    // prints (left child)->(parent)->(right child)  
{
    if(pp==NULL)
	return;
	                                                                
	printInOrder(pp->left); 
	cout<<pp->data<<" ";   	 
	printInOrder(pp->right);	 
	
	return;
}

void printLevelOrderTraversal(BinaryTreeNode<int> *rp)
{                                
    if(rp==NULL)
	return;
	
	queue<BinaryTreeNode<int>*> ppList;                         
	ppList.push(rp);
	ppList.push(NULL);                                        // NULL = indicator of line change, after printing a level                         
	while(ppList.size() != 0)              
	{
	   BinaryTreeNode<int> *pp = ppList.front();              
	   ppList.pop();  
	   
	   if(pp == NULL)                                         // NULL means no more pp in current level, so change line
	   {  cout<<endl;
	                                                                            
	      if(ppList.size() != 0)                        
	      ppList.push(NULL);  }                               // NULL means no more cp in next level, so store NULL for next line change
	   else        
	   {  cout<<pp->data<<" ";   
	     
	      if(pp->left != NULL)                                // storing left child pointer     
	      ppList.push(pp->left); 
	      if(pp->right != NULL)                               // storing right child pointer        
	      ppList.push(pp->right);  }  
    }
}	  

void printZigZagOrderTraversal(BinaryTreeNode<int> *rp)
{                                
    if(rp==NULL)
	return;
	
	stack<BinaryTreeNode<int>*> sL,sR;             
	            
	sL.push(rp);          
	while(sL.size()!=0 || sR.size()!=0)              
	{
	   while(sL.size()!=0)                                    // printing even level (left to right) by (sL) & storing next level in (sR)
	   {  BinaryTreeNode<int> *pp = sL.top();              
	      sL.pop();  
	      
	      cout<<pp->data<<" "; 
	      if(pp->left != NULL)                                   
	      sR.push(pp->left); 
	      if(pp->right != NULL)                                   
	      sR.push(pp->right);  }   
	   cout<<endl;
	                                                  
	   while(sR.size()!=0)                                    // printing odd level (right to left) by (sR) & storing next level in (sL)
	   {  BinaryTreeNode<int> *pp = sR.top();              
	      sR.pop();  
	      
	      cout<<pp->data<<" "; 
	      if(pp->left != NULL)                                   
	      sL.push(pp->left); 
	      if(pp->right != NULL)                                   
	      sL.push(pp->right);  }  
	   cout<<endl;
    }
}	  
         
int main()
{ 
    BinaryTreeNode<int> *rp = storeBTLevelWise();       
    
    cout<<"\n\n\nTotal no. of nodes: "<<totalNodes(rp)<<endl;
    cout<<"Is node 6 present in binary tree: "<<(isNodePresent(rp,6) ? "true" : "false")<<endl;
    cout<<"Height of the binary tree is: "<<getHeight(rp)<<endl;  
    
    cout<<"\nPreOrder: ";                                                     
    printPreOrder(rp); 
    cout<<"\nPostOrder: ";                                 
    printPostOrder(rp); 
    cout<<"\nInOrder: ";                          
    printInOrder(rp);    
    cout<<"\n\nLevelOrderTraversal: \n";                          
    printLevelOrderTraversal(rp);  
    cout<<"\nZigZagOrderTraversal: \n";                          
    printZigZagOrderTraversal(rp); 
	 
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
 















