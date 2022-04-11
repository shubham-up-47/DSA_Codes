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

Node* storeLL()                
{ 
	int data;
	Node *head=NULL, *tail=NULL;       
	 
	cin>>data;
	while(data != -1)
	{   
	    Node *np = new Node(data); 
	    if(head==NULL)
	    {   head = np;
	        tail = np;   } 
		else
		{   tail->next = np;
		    tail = np;   }
		
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
 
Node* mergeTwoSortedLL(Node* head1, Node* head2)
{
	if(head1==NULL)
	return head2;
	else if(head2==NULL)
	return head1;
	
	
	Node *head;
    if(head1->data < head2->data)
	{   head = head1;
	    head1 = head1->next;   }
	else
	{   head = head2;
	    head2 = head2->next;   } 
	   
	Node *t; 
	for(t=head;  head1!=NULL||head2!=NULL;  )
	{
	  	if(head1==NULL)
	    {   t->next = head2;
		    break;   }
	    else if(head2==NULL)
	    {   t->next = head1;
	        break;   } 
	    else if(head1->data < head2->data)
    	{  t->next = head1;
    	   t = head1;
     	   head1 = head1->next;  }
    	else
    	{  t->next = head2;
    	   t = head2;
    	   head2 = head2->next;  }	
	}   
	  
	return head;
}

Node* midNodeLL(Node *head)
{ 
    if(head==NULL)
    return head;
    
	Node *Slow=head, *Fast=head; 
	while(Fast->next!=NULL && Fast->next->next!=NULL)
	{  Slow = Slow->next;
	   Fast = Fast->next->next;  }
	   
	return Slow;	 
}

Node* mergeSortLL(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
     
    Node *head1 = head; 
    Node *midN = midNodeLL(head);
    Node *head2 = midN->next; 
    midN->next = NULL;
    
    head1 = mergeSortLL(head1);
    head2 = mergeSortLL(head2);
    head = mergeTwoSortedLL(head1, head2);      // merge sorted LL1 & LL2
 
 
    return head;
}
 

int main()
{
    Node *LL = storeLL();                       // taking input until -1 is entered ( [head]->[node]->[node].......->[node]->[node]->NULL ) 

    cout<<"\nAfter Merge Sort -\n"; 
    LL = mergeSortLL(LL);
    printLL(LL);  
}










 
