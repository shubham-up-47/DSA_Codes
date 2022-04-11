#include <bits/stdc++.h>                                     
using namespace std;

 
template <typename T>               
class TreeNode                                                                                                                            
{     public:
	T data;                                        
	vector<TreeNode<T>*> children;                  
	
	TreeNode(T d)                                                  
	{  this->data = d;  }
   
   ~TreeNode()                                      
    {  for(int i=0; i<this->children.size(); i++)
       delete this->children[i];  }	                                             
};                               
                                                                        
TreeNode<int>* storeTreeLevelWise()               
{
    int r;
	cout<<"Enter root data: ";
	cin>>r;
	
	TreeNode<int> *rp = new TreeNode<int>(r);      
	queue<TreeNode<int>*> ppList;
	ppList.push(rp);
	
	while(ppList.size() != 0)
	{
	   TreeNode<int> *pp = ppList.front();
	   ppList.pop();
	   
	   int n;
	   cout<<"Enter no of children of "<<pp->data<<": ";
	   cin>>n;
	   
	   for(int i=0; i<n; i++)                         
	   {  int c;
	      cout<<"Enter "<<i<<"th child of "<<pp->data<<": ";
	      cin>>c;
	      
	      TreeNode<int> *cp = new TreeNode<int>(c);      
	      pp->children.push_back(cp);
	      ppList.push(cp);   }	
    }
 
	return rp;
}
                                               
void printTreeLevelWise(TreeNode<int> *rp)
{                                
    if(rp==NULL)
	return;
	
	queue<TreeNode<int>*> ppList;                         
	ppList.push(rp);
	
	while(ppList.size() != 0)
	{
	   TreeNode<int> *pp = ppList.front();
	   ppList.pop();
	   
	   cout<<pp->data<<": ";
	   for(int i=0; i<pp->children.size(); i++)           
	   {   if(i != 0)
	       cout<<",";
	       
	       cout<<pp->children[i]->data;                    
	       ppList.push(pp->children[i]);   } 
	   cout<<endl;
    }
}	                                                                                             
    
void printNodesAtLevelK(TreeNode<int> *pp, int k)
{
    if(pp==NULL)
	return;
	else if(k==0)
	{  cout<<pp->data<<" ";
	   return;  }
	   
	for(int i=0; i<pp->children.size(); i++)
	printNodesAtLevelK(pp->children[i], k-1);   
	
    return;
}	
	
int totalNodes(TreeNode<int> *pp)
{
	if(pp==NULL)
	return 0;
	 
	int count = 1;                                         // count parent/current node
	for(int i=0; i<pp->children.size(); i++)
	count += totalNodes(pp->children[i]);                  // count all children
	
	return count; 
}
 
int getHeight(TreeNode<int> *pp)                           // height = no of levels
{
	if(pp==NULL)
	return 0;
	
	int heightCT = 0;
	for(int i=0; i<pp->children.size(); i++)
	heightCT = max(heightCT, getHeight(pp->children[i]));  // finding height of maxHeightChildTree (CT) 
       
	return (heightCT+1);                                   // include parent/current node height while returning   
}
                                          
int totalLeafNodes(TreeNode<int> *pp)                   
{
	if(pp==NULL)
	return 0;
	else if(pp->children.size()==0)                        // leaf node (node with no children)
	return 1;
	
	int count = 0;                                                                                          
	for(int i=0; i<pp->children.size(); i++)
	count += totalLeafNodes(pp->children[i]);              // counting no of leaf nodes
 
	return count; 
}
 
void printPreOrder(TreeNode<int> *pp)                      // prints (parent)->(children)  
{
    if(pp==NULL)
	return;
	
	cout<<pp->data<<" ";                                   // pre
	for(int i=0; i<pp->children.size(); i++) 
	printPreOrder(pp->children[i]);	 
	
	return;
}

void printPostOrder(TreeNode<int> *pp)                     // prints (children)->(parent)  
{
    if(pp==NULL)
	return;
	
	for(int i=0; i<pp->children.size(); i++)
	printPostOrder(pp->children[i]);	 
	cout<<pp->data<<" ";                                   // post  
	
	return;
}
                                                                          
 
int main()
{
	TreeNode<int> *np = new TreeNode<int>(7);              // dynamic node 
	
    TreeNode<int> *rp = storeTreeLevelWise();              // creating tree
    cout<<endl<<endl;
    
    printTreeLevelWise(rp);
    cout<<endl;
    
    cout<<"Total no. of nodes: "<<totalNodes(rp)<<endl;
    cout<<"Total no. of leaf nodes: "<<totalLeafNodes(rp)<<endl;
    cout<<"Height of the tree is: "<<getHeight(rp)<<endl;
    cout<<"Nodes at Level 2 are: ";
    printNodesAtLevelK(rp, 2);
    cout<<endl<<endl;

    cout<<"PreOrder: ";                                    // prints (parent)->(children)                  
    printPreOrder(rp);
    cout<<endl;
    cout<<"PostOrder: ";                                   // prints (children)->(parent)   
    printPostOrder(rp);
    cout<<endl<<endl;                                              

    delete rp;                                                     
}
 
 
 /*
 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

            1           Level 0 
           /|\
          / | \
         2  3  4        Level 1
        /|  |\
       / |  | \
      5  6  7  8        Level 2
                \
                 \
			      9     Level 3
 */

























