#include <bits/stdc++.h>
using namespace std;
                                 
// STORING & PRINTING TREE LEVEL WISE

template <typename T>               
class TreeNode                                         // defining TreeNode                                                                                    
{     public:
	T data;                                            // data of current node
	vector<TreeNode<T>*> children;                     // vector storing children node addresses
	
	TreeNode(T d)                                      // constructor
	{  data = d;  }
   
   ~TreeNode()                                         // distructor 
    {  for(int i=0; i<this->children.size(); i++)
       delete this->children[i];  }	                   // deleting each child individually                             
};                               
                                                                        
TreeNode<int>* storeTreeLevelWise()               
{
    int r;
	cout<<"Enter root data: ";
	cin>>r;
	
	TreeNode<int> *rp = new TreeNode<int>(r);          // making root node dynamically
	queue<TreeNode<int>*> ppList;                      // queue storing pp level wise 
	ppList.push(rp);
	
	while(ppList.size() != 0)    // for all parent at a specific level, store all child pointer in (queue) & (corrresponding vector array)
	{
	   TreeNode<int> *pp = ppList.front();             // current parent        
	   ppList.pop();
	   
	   int n;                               
	   cout<<"Enter no of children of "<<pp->data<<": ";
	   cin>>n;                                         // no of children of current parent
	    
	   for(int i=0; i<n; i++)                        
	   {  int c;
	      cout<<"Enter "<<i<<"th child of "<<pp->data<<": ";
	      cin>>c;
	      
	      TreeNode<int> *cp = new TreeNode<int>(c);    // making child node dynamically
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
	
	while(ppList.size() != 0)      // for all parent at a specific level, print the children & store all child pointer in (queue) 
	{
	   TreeNode<int> *pp = ppList.front();             // current parent
	   ppList.pop();
	   
	   cout<<pp->data<<": ";
	   for(int i=0; i<pp->children.size(); i++)        // no of children of current parent
	   {   if(i != 0)
	       cout<<",";
	       
	       cout<<pp->children[i]->data;                // children array stores addresses
	       ppList.push(pp->children[i]);   } 
	   cout<<endl;
    }
}	                   
                               
 
int main()
{
    TreeNode<int> *rp = storeTreeLevelWise();          // iterative
    cout<<endl<<endl;
    
    cout<<"Printing tree level wise\n";
    printTreeLevelWise(rp);                            // iterative
    cout<<endl;
 
    delete rp;                                         // distructor called (deletes complete tree)                
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


 // use (recursion) most of the times to solve question related to (tree) considering (current node) as (parent node) 
 // Genric Tree = each parent can have any no of children   (Base Case -> pp->children.size()==0)
 // Binary Tree = each parent can have 0 / 1 / 2 children   (Base Case -> pp==NULL) 
 // (r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   


















