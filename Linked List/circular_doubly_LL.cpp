#include <bits/stdc++.h>
using namespace std;
 
 
class Node                                                          // circular doubly Linked List       
{     public:
    int data;                             
    Node *next; 
	Node *prev;                          
   
    Node(int d)                       
    {  data = d;
       next = NULL;
	   prev = NULL;  }	 
};

Node* storeLinkedList()                
{ 
	int data;
	Node *head=NULL, *tail=NULL;       
	 
	cin>>data;
	while(data != -1)
	{   
	    Node *np = new Node(data); 
	    if(head==NULL)
	    {  head = np;
	       tail = np;
           tail->next = head;
		   head->prev = tail;  } 
		else
		{  tail->next = np;
		   np->prev = tail;
		   
		   tail = np;
		   tail->next = head;
		   head->prev = tail;  }
		
		cin>>data;    
	}
	
	return head; 
 } 

void print(Node *head)                                              // printing linked list                                 
{ 
    if(head==NULL)
    return;

    cout<<"LL: ";
    cout<<head->data<<" ";
    for(Node *t=head->next; t!=head; t=t->next)
    cout<<t->data<<" ";
 
    cout<<endl;
}
                 
int sizeOfLinkedList(Node *head)
{
	if(head==NULL)
	return 0;
	
    int c=1;
	for(Node *t=head->next; t!=head;  t=t->next,c++);
	return c;	 
}

Node* insertNodeAtIndexK(Node *head)                                // storing input Linked List  
{ 
    cout<<"\nEnter Value & Index No to insert new node: ";
	int data,k;
	cin>>data>>k; 
    Node *np = new Node(data);
    
    
    if(k==0)
    {   if(head==NULL)
        {  np->next = np;
           np->prev = np;  }
        else
        {  np->next = head; 
           head->prev = np;
           
           Node *tail; 
	       for(tail=head; tail->next!=head; tail=tail->next); 
                                                        	                                       	     
	       tail->next = np;
		   np->prev = tail;   }
	      
        head = np;
        return head;   }
    if(k==1)
	{   Node *p = head->next;
	
	    head->next = np;
	    np->prev = head;
	    
	    np->next = p; 
		p->prev = np;  
		 
        return head;   }
 
    Node *temp = head->next;
    for(int i=1;  i<k-1&&temp!=head;  i++,temp=temp->next);         // now [temp] = node at index k-1 
     
	if(temp!=head)
	{   Node *p = temp->next;
	
	    temp->next = np;
	    np->prev = temp;
	    
	    np->next = p;
		p->prev = np;   }
 
	return head; 
 } 

Node* deleteNodeAtIndexK(Node *head)                                // storing input Linked List  
{ 
    cout<<"\nEnter Index No to delete the node: ";
	int k;
	cin>>k; 
	       
    if(k==0)
    {   Node *t;
        int c=1;
	    for(t=head; t->next!=head;  t=t->next,c++);
	    if(c==1)
	    return NULL;
	    
	    t->next = head->next; 
	    head->next->prev = t;
	    
	    delete head;
	    head = t->next;
        return head;   }
    else if(k==1) 
	{   Node *p = head->next;
	    head->next = head->next->next;
	    head->next->next->prev = head;
	    delete p;  
		return head; }
        
    Node *temp = head->next;                                               
    for(int i=1;  i<k-1&&temp!=head;  i++,temp=temp->next);         // now [temp] = node at index k-1 
       
	if(temp!=head && temp->next!=head)
	{   Node *p = temp->next;
	
	    temp->next = p->next;  
	    p->next->prev = temp; 
	    
	    delete p;  }
 
	return head; 
} 

Node* reverseLinkedList(Node *head)
{
	cout<<"\nAfter reversing the Linked List\n";
	
    if(head==NULL)
    return NULL;
    
    Node *tail;
	for(Node *t=head->next; t!=head; t=t->next)
	{  if(t->next==head)
	   tail = t;  }
	
	for(Node *t=tail; t!=head; t=t->next)
	{  Node *p = t->next;
	   t->next = t->prev;
	   t->prev = p;  }
	 
	Node *p =  head->next;  
	head->next = head->prev;
	head->prev = p; 
	
	head = tail; 
	return head; 
}
 
 
int main()
{
    Node *LL = storeLinkedList();                                   // taking input until -1 is entered ( [head]->[node]....->[node]->NULL ) 
 
    cout<<"\nSize of LL: "<<sizeOfLinkedList(LL)<<endl; 
    print(LL); 
    LL = insertNodeAtIndexK(LL);
    print(LL);                        
    LL = deleteNodeAtIndexK(LL);
    print(LL);                      
    LL = reverseLinkedList(LL);
    print(LL); 
}

 
   
   
   
   
   
   
   
   
   
   
   
   
  
