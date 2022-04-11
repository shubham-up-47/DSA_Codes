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
	    {  head = np;
	       tail = np;  } 
		else
		{  tail->next = np;
		   tail = np;  }
		
		cin>>data;    
	}
	
	return head; 
}  
 
Node* midNodeLL(Node *head)
{
    int n=0; 
	for(Node *t=head;  t!=NULL;  t=t->next,n++);
	
	Node *midN=head; 
	for(int i=0;  i<(n-1)/2;  midN=midN->next,i++);     // loop runs till [(n-1)/2]th index of LL
	
	return midN;	 
}

/*
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
*/ 
 
int main()
{
    Node *LL = storeLL();      // taking input until -1 is entered ( [head]->[node]->[node].......->[node]->[node]->NULL ) 

    Node *midN = midNodeLL(LL);
    cout<<"\nMid Node of LL: "<<midN->data;  
}









