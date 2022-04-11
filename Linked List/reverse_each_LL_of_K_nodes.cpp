#include <bits/stdc++.h>
using namespace std;
 
                                                 
class Node 
{     public:
    int data;                           
    Node *next;                         
   
    Node(int d)                       
    {  data = d;
       next = NULL;  }	 
};

void addElementInLL(Node *np, Node* &head, Node* &tail)
{
	if(head==NULL)
	{  head = np;
	   tail = np;  } 
	else
	{  tail->next = np;
	   tail = np;  }
}

Node* storeLL()                
{ 
	int data;
	Node *head=NULL, *tail=NULL;       
	 
	cin>>data;
	while(data != -1)
	{   
	    Node *np = new Node(data); 
	    addElementInLL(np, head, tail);
		
		cin>>data;    
	}
	
	return head; 
}             

pair<Node*,Node*> reverseLL(Node *head)
{                                                                         // considering first=head & second=tail in pair class                    
    if(head==NULL || head->next==NULL)
    {  pair<Node*,Node*>  r(head,head);
       return r;  }
       
    pair<Node*,Node*>  r = reverseLL(head->next); 
    r.second->next = head;
    r.second = head;                                                      // updating tail
    r.second->next = NULL; 
	     
    return r;
}                 
                                                                                                                                                                           
Node* reverseEachLLof_K_nodesWhileLLtraversal(Node *head, int k)        
{
	if(k==0 || head==NULL || head->next==NULL)
	return head;
 
                                                                                            
    Node *t = head;
	for(int i=1;  i<k && t->next!=NULL;  i++,t=t->next);                  // skip till K
   	   
	Node *headR = t->next;                                                // recursion head     
	t->next = NULL;
	
	pair<Node*,Node*> r = reverseLL(head);                                // (first=head, second=tail) of k sized reversed LL                   
	head = r.first;
	r.second->next = reverseEachLLof_K_nodesWhileLLtraversal(headR, k);
  
                                                                                                        
	return head; 
}
 
void printLL(Node *head)                                                      
{ 
    cout<<"\nLL after doing operation: ";
	while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}
                                 
int main()
{
	int k=3;
    Node *LL = storeLL();                                                 // storing input number (until -1 is entered)  
 
    LL = reverseEachLLof_K_nodesWhileLLtraversal(LL, k);
                                    
    printLL(LL);
	cout<<endl<<endl;
}

 
//  0 2 8 1 3 7 5 7 6 4 9 -1    
  
  
  
  







