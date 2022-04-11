#include <bits/stdc++.h>
using namespace std;
 
 
class Node                                                      // circular singly Linked List       
{     public:
    int data;                             
    Node *next;                           
   
    Node(int d)                       
    {  data = d;
       next = NULL;  }	 
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
		   tail->next = head;  } 
		else
		{  tail->next = np;
		   tail = np;
		   tail->next = head;  }
		
		cin>>data;    
	}
	
	return head; 
 } 

void print(Node *head)                                          // printing linked list                                 
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

Node* insertNodeAtIndexK(Node *head)                            // storing input Linked List  
{ 
    cout<<"\nEnter Value & Index No to insert new node: ";
	int data,k;
	cin>>data>>k; 
    Node *np = new Node(data);
    
    
    if(k==0)
    {   if(head==NULL)
        np->next = np;
        else
        {  np->next = head; 
           Node *t; 
	       for(t=head; t->next!=head;  t=t->next);   
	       t->next = np;   }
	   
        head = np;
        return head;   }
    if(k==1)
	{   Node *p = head->next;
	    head->next = np;
	    np->next = p;   
	     
        return head;   }
 
    Node *temp = head->next;
    for(int i=1;  i<k-1&&temp!=head;  i++,temp=temp->next);     // now [temp] = node at index k-1 
     
	if(temp!=head)
	{   Node *p = temp->next;
	    temp->next = np;
	    np->next = p;   }
 
	return head; 
 } 

Node* deleteNodeAtIndexK(Node *head)                            // storing input Linked List  
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
	    delete head;
	    head = t->next;
        return head;   }
    else if(k==1) 
	{   Node *p = head->next;
	    head->next = head->next->next;
	    delete p;  
		return head; }
        
    Node *temp = head->next;                                               
    for(int i=1;  i<k-1&&temp!=head;  i++,temp=temp->next);     // now [temp] = node at index k-1 
       
	if(temp!=head && temp->next!=head)
	{   Node *p = temp->next;
	    temp->next = temp->next->next;
	    delete p;  }
 
	return head; 
} 

Node* reverseLinkedList(Node *head)
{
	cout<<"\nAfter reversing the Linked List\n";
	
	
	Node *preN=head, *currN=head->next; 
	while(currN!=head)
	{  Node *postN = currN->next;
	
	   currN->next = preN;                                      // from [preN]->[currN] to [preN]<-[currN]
	 
	   preN = currN;
	   currN = postN;  }
	currN->next = preN;
	
	return preN; 
}
 
 
int main()
{
    Node *LL = storeLinkedList();                               // taking input until -1 is entered ( [head]->[node]......->[node]->NULL ) 

    cout<<"\nSize of LL: "<<sizeOfLinkedList(LL)<<endl; 
    print(LL); 
    LL = insertNodeAtIndexK(LL);
    print(LL); 
    LL = deleteNodeAtIndexK(LL);
    print(LL); 
    LL = reverseLinkedList(LL);
    print(LL); 
}


 
