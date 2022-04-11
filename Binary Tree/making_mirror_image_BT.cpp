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
     
void makeMirrorImageBT(BinaryTreeNode<int> *pp) 
{
    if(pp==NULL)
	return;
	else                                                      // swapping left child & right child
	{  BinaryTreeNode<int> *temp = pp->left;
	   pp->left = pp->right;
	   pp->right = temp;  }
	                              
	makeMirrorImageBT(pp->left);	 
	makeMirrorImageBT(pp->right);	 
		
	return;
}                                                                                  /*
            1                       1                          1       
           / \                     / \                        / \ 
          2   3        =>         3   2         =>           3   2  
              /\                 /\                         /\
             4  5               4  5                       5  4                    */
             
int main()
{ 
    BinaryTreeNode<int> *rp = storeBTLevelWise(); 
    cout<<endl<<endl;      
     
     
	cout<<"\nBinary tree initially\n";
    printBTLevelWise(rp);   
	  
	makeMirrorImageBT(rp);
	
	cout<<"\nBinary tree after taking mirror image\n";
    printBTLevelWise(rp);                                      


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
 














