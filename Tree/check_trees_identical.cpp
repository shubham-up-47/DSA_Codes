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
 

bool comparePP(TreeNode<int> *pp1, TreeNode<int> *pp2)
{
   if(pp1==NULL && pp2==NULL)
   return 1;
   else if(pp1==NULL || pp2==NULL)
   return 0;
   else if(pp1->data != pp2->data)	
   return 0;
   else if(pp1->children.size() != pp2->children.size())	
   return 0;
   else 
   return 1;
}             
                                                     
                  
bool  checkTreesIdentical(TreeNode<int> *pp1, TreeNode<int> *pp2)
{
	if(comparePP(pp1,pp2)==0)
	return 0;
	
	
	for(int i=0; i<pp1->children.size(); i++)
	{   TreeNode<int> *cp1 = pp1->children[i];
	    TreeNode<int> *cp2 = pp2->children[i];
	    
     	if(checkTreesIdentical(cp1,cp2)==0)
    	return 0;   }
	
	
	return 1; 
}
 
                           
int main()
{
	cout<<"\tEnter 1st tree data\n";
    TreeNode<int> *rp1 = storeTreeLevelWise();
    cout<<endl<<endl;

	cout<<"\tEnter 2nd tree data\n";
    TreeNode<int> *rp2 = storeTreeLevelWise();
    cout<<endl<<endl;
    
    if(checkTreesIdentical(rp1,rp2)) 
    cout<<"\n\nBoth trees are identical\n\n";
	else 
    cout<<"\n\nBoth trees are not identical\n\n";
    
    delete rp1,rp2;                                                     
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








 


 

