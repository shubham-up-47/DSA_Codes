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
	
	while(ppList.size() != 0)                       // for all parent at a specific level, print the children & store all child pointer in (queue) 
	{
	   TreeNode<int> *pp = ppList.front();          // current parent
	   ppList.pop();
	   
	   cout<<pp->data<<": ";
	   for(int i=0; i<pp->children.size(); i++)     // no of children of current parent
	   {   if(i != 0)
	       cout<<",";
	       
	       cout<<pp->children[i]->data;             // children array stores addresses
	       ppList.push(pp->children[i]);   } 
	   cout<<endl;
    }
}	                   
                                                     
                  
void  replaceNodeByDepthValue(TreeNode<int> *pp, int d=0)
{
	if(pp==NULL)
	return;
	
	
	pp->data = d;
	
	for(int i=0; i<pp->children.size(); i++)
	replaceNodeByDepthValue(pp->children[i], d+1);
	
	
	return; 
}
 
                           
int main()
{
    TreeNode<int> *rp = storeTreeLevelWise();
    cout<<endl<<endl;

    replaceNodeByDepthValue(rp);
    
    cout<<"\nTree after replacing node data by depth value"<<endl; 
    printTreeLevelWise(rp);
    
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












 










