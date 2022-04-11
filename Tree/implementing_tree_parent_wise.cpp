#include <bits/stdc++.h>
using namespace std;

// STORING & PRINTING TREE PARENT WISE

template <typename T> 
class TreeNode                                          // defining TreeNode                                                                                    
{      public:
	T data;                                             // data of current node
	vector<TreeNode<T>*> children;                      // vector storing cp 
	
	TreeNode(T d)                                       // constructor
	{  data = d;  } 
};     

TreeNode<int>* storeTreeParentWise()                       
{
    int p;
	cout<<"Enter parent data: ";
	cin>>p;
	 
	TreeNode<int> *pp = new TreeNode<int>(p);           // making parent/current node dynamically ( T = int )
                                                                             
	int n;
	cout<<"Enter no of children of "<<pp->data<<": ";  
	cin>>n;
	   
	for(int i=0; i<n; i++)                              // store children in vector array 
	{  TreeNode<int> *cp = storeTreeParentWise();    
	   pp->children.push_back(cp);  }
 
 
	return pp;
}
                                                           
void printTreeParentWise(TreeNode<int> *pp)
{                                
    if(pp==NULL)
	return;
	
	
	cout<<pp->data<<": ";                               // print parent 
	for(int i=0; i<pp->children.size(); i++)            // print children 
    cout<<pp->children[i]->data<<",";                   // children array stores addresses
	cout<<endl;                                         
	
	for(int i=0; i<pp->children.size(); i++) 
	printTreeParentWise(pp->children[i]);               // print children trees
	
	
	return;
}	                   
                                                                                                                                   
void deleteTree(TreeNode<int> *pp)                                
{  
   for(int i=0; i<pp->children.size(); i++)
   deleteTree(pp->children[i]);                         // first delete each child then parent
   
   delete pp;                                           // inbuilt distructor of TreeNode class is called
}	                             
 
int main()
{
    TreeNode<int> *rp = storeTreeParentWise();          // recursive
    cout<<endl<<endl;
    
    cout<<"Printing tree parent wise\n";
    printTreeParentWise(rp);                            // recursive
    cout<<endl;
    
    deleteTree(rp);                                     // deletes complete tree            
}
  
                                           
 /*
 1 3 2 2 5 0 6 0 3 2 7 0 8 1 9 0 4 0

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










 






 
