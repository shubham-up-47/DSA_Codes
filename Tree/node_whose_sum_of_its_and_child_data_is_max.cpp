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
  
int sumOfChildData(TreeNode<int> *pp)
{
   int r = pp->data;
   
   for(int i=0; i<pp->children.size(); i++)
   r += pp->children[i]->data;	
 
   return r;
}             
                                                     
                  
TreeNode<int>*  findNodeWhoseSumOfItsAndChildNodeDataIsMax(TreeNode<int> *pp)
{
	if(pp==NULL)
	return pp;
	
	int r = sumOfChildData(pp);
	TreeNode<int> *rp = pp;
	
	for(int i=0; i<pp->children.size(); i++)
	{   
	    TreeNode<int> *tp = findNodeWhoseSumOfItsAndChildNodeDataIsMax(pp->children[i]);        // temp pointer
	    int t = sumOfChildData(tp);
	    
     	if(t > r)
    	{  r = t;
    	   rp = tp;  }
    }
	
	return rp; 
}
 
                           
int main()
{
	cout<<"\tEnter tree data\n";
    TreeNode<int> *rp = storeTreeLevelWise();
    cout<<endl<<endl;
 
    TreeNode<int> *tp = findNodeWhoseSumOfItsAndChildNodeDataIsMax(rp);
     
    cout<<"\n\nNode whose (sum of node data and child node data is max) is: "<<tp->data;
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








 


 


