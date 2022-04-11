#include <bits/stdc++.h>
using namespace std;
 
 
class Node                                                            // doubly linked list
{     public:
    int data;                           
    Node *next;                         
    Node *prev;
    
    Node(int d)                       
    {  data = d;
       next = NULL;
	   prev = NULL;  }	 
};
  
Node* storeLL()                
{ 
	int data;
	Node *head=NULL, *tail=NULL;       
	 
	cin>>data;
	while(data != -1)
	{   
	    Node *np = new Node(data); 
	    if(head==NULL)
	    {  head = np;
	       tail = np;  } 
		else
		{  tail->next = np;
		   np->prev = tail;
		   tail = np;  }
		
		cin>>data;    
	}
	
	return head; 
}  
 
void printLL(Node *head)                                                      
{ 
    cout<<"LL: ";
	while(head != NULL)
	{   cout<<head->data<<" ";
        head = head->next;  }
    cout<<endl;
} 

int sizeLL(Node *head)
{
    int c;
	for(c=0;  head!=NULL;  head=head->next,c++);
	return c;	 
}
 
Node* insertNodeAtIndexK(Node *head)                                  // storing input Linked List  
{ 
    cout<<"\nEnter Value & Index No to insert new node: ";
	int data,k;
	cin>>data>>k; 
    Node *np = new Node(data);
    
    
    if(k==0)
    {   np->next = head;
        head->prev = np;
        
        head = np;
        return head;   }
    
    Node *temp = head;
    for(int i=0;  i<k-1&&temp!=NULL;  i++,temp=temp->next);           // now [temp] = node at index k-1 
     
	if(temp!=NULL)
	{   Node *p = temp->next;
	
	    temp->next = np;
	    np->prev = temp;
	    
	    np->next = p;
		p->prev = np;   }
 
	return head; 
 } 
 
Node* deleteNodeAtIndexK(Node *head)                                  // storing input Linked List  
{ 
    cout<<"\nEnter Index No to delete the node: ";
	int k;
	cin>>k; 
	
	
    Node *temp = head;
     
    if(k==0)
    {   head = head->next; 
        head->prev = NULL;
	    delete temp;
        return head;   }
                                                   
    for(int i=0;  i<k-1&&temp!=NULL;  i++,temp=temp->next);           // now [temp] = node at index k-1 
       
	if(temp!=NULL && temp->next!=NULL)
	{   Node *p = temp->next;
	
	    temp->next->next->prev = temp;
	    temp->next = temp->next->next;
	    
	    delete p;   }
 
	return head; 
} 

Node* reverseLL(Node *head)
{
	cout<<"\nAfter reversing the Linked List -\n";
	 
	for(Node *t=head; t!=NULL; t=t->next)
	{  if(t->next==NULL)
	   head = t;  }
	
	for(Node *t=head; t!=NULL; t=t->next)
	{  Node *p = t->next;
	   t->next = t->prev;
	   t->prev = p;  }
	 
	return head; 
}
 
   
int main()
{
    Node *LL = storeLL();                                             // taking input until -1 is entered ( [head]->[node]....->[node]->NULL ) 

    cout<<"\nSize of LL: "<<sizeLL(LL)<<endl; 
    printLL(LL); 
    LL = insertNodeAtIndexK(LL);
    printLL(LL); 
    LL = deleteNodeAtIndexK(LL);
    printLL(LL); 
    LL = reverseLL(LL);
    printLL(LL); 
}













 
