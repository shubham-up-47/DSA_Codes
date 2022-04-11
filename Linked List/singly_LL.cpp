#include <bits/stdc++.h>
using namespace std;
 
 
class Node                                     
{     public:
    int data;                                                 // data of current node of singly Linked List
    Node *next;                                               // address of next node of singly Linked List 
   
    Node(int d)                                               // parametrized constructor 
    {  data = d;
       next = NULL;  }	 
};

Node* storeLinkedList()                                       // storing input Linked List  
{ 
	int data;
	Node *head=NULL, *tail=NULL;                              // maintaing head & tail while storing so { O(n) } 
	 
	cin>>data;
	while(data != -1)
	{   
	    Node *np = new Node(data); 
	    if(head==NULL)
	    {  head = np;
	       tail = np;  } 
		else
		{  tail->next = np;
		   tail = np;  }
		
		cin>>data;    
	}
	
	return head; 
 } 

void print(Node *head)                                        // printing linked list                                 
{ 
    cout<<"LL: ";
	while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}

    // ITERATIVE CODES

int sizeOfLinkedList(Node *head)
{
    int c;
	for(c=0;  head!=NULL;  head=head->next,c++);
	return c;	 
}

Node* insertNodeAtIndexK(Node *head)                          // storing input Linked List  
{ 
    cout<<"\nEnter Value & Index No to insert new node: ";
	int data,k;
	cin>>data>>k; 
    Node *np = new Node(data);
    
    
    if(k==0)
    {   np->next = head;
        head = np;
        return head;   }
    
    Node *temp = head;
    for(int i=0;  i<k-1&&temp!=NULL;  i++,temp=temp->next);   // now [temp] = node at index k-1 
     
	if(temp!=NULL)
	{   Node *p = temp->next;
	    temp->next = np;
	    np->next = p;   }
 
	return head; 
 } 

Node* deleteNodeAtIndexK(Node *head)                          // storing input Linked List  
{ 
    cout<<"\nEnter Index No to delete the node: ";
	int k;
	cin>>k; 
	
	
    Node *temp = head;
     
    if(k==0)
    {   head = head->next; 
	    delete temp;
        return head;   }
                                                   
    for(int i=0;  i<k-1&&temp!=NULL;  i++,temp=temp->next);   // now [temp] = node at index k-1 
       
	if(temp!=NULL && temp->next!=NULL)
	{   Node *p = temp->next;
	    temp->next = temp->next->next;
	    delete p;  }
 
	return head; 
} 

Node* reverseLinkedList(Node *head)
{
	cout<<"\nAfter reversing the Linked List -\n";
	
	
	Node *preN=NULL, *currN=head;
	
	while(currN!=NULL)
	{  Node *postN = currN->next;
	
	   currN->next = preN;                                    // from [preN]->[currN] to [preN]<-[currN]
	 
	   preN = currN;
	   currN = postN;  }
	
	return preN; 
}

/*          // RECURSIVE CODES 

int sizeOfLinkedList(Node *head)
{
	if(head==NULL)
	return 0;
	
    int c = 1 +	sizeOfLinkedList(head->next);
    
	return c;	 
}

Node* insertNodeAtIndexK(Node *head, int x, int k)            // storing input Linked List  
{ 
	if(head==NULL)
	return head;
	else if(k==0)
    {   Node *np = new Node(x);
        np->next = head;
        head = np;
        return head;   }
    
    head->next = insertNodeAtIndexK(head->next, k-1, x);
    
	return head; 
 } 

Node* deleteNodeAtIndexK(Node *head, int k)                   // storing input Linked List  
{ 
	if(head==NULL)
	return head;
	else if(k==0)
    {   Node *temp = head; 
	    head = head->next; 
	    delete temp;
        return head;   }
     
    head->next = deleteNodeAtIndexK(head->next, k-1);
    
	return head; 
} 

pair<Node*,Node*> reverseLL(Node *head)
{                                                             // considering first=head & second=tail in pair class                    
    if(head==NULL || head->next==NULL)
    {  pair<Node*,Node*>  r(head,head);
       return r;  }
      
    
    pair<Node*,Node*>  r = reverseLL(head->next);
    
    r.second->next = head;
    r.second = head;                                          // updating tail
    r.second->next = NULL; 
	    
    return r;
}

Node* reverseLinkedList1(Node *head)
{   return reverseLL(head).first;   }
 
Node* reverseLinkedList2(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
       
    Node *headR = reverseLinkedList2(head->next);
    
    Node *tailR = head->next;
    tailR->next = head;
    tailR = head;                                             // updating tail 
    tailR->next = NULL;
   
	return headR; 
}
 
*/

int main()
{
    Node *LL = storeLinkedList();                             // taking input until -1 is entered ([head]->[node]->[node]...->[node]->[node]->NULL) 

    cout<<"\nSize of LL: "<<sizeOfLinkedList(LL)<<endl; 
    print(LL); 
    LL = insertNodeAtIndexK(LL);
    print(LL); 
    LL = deleteNodeAtIndexK(LL);
    print(LL); 
    LL = reverseLinkedList(LL);
    print(LL); 
}














 
  
 
