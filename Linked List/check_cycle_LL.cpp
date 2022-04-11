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
 
bool checkCycleInLL(Node *head)
{
	unordered_map<Node*,int>  h;
	 
	for(Node *t=head; t!=NULL; t=t->next)
	{   if(h[t] > 0)
        return 1;
		else
		h[t]++;   }
  
    return 0;	 	 
}
                                                                                                                                                     
/*
bool checkCycleInLL(Node *head)
{  
	Node *Slow=head, *Fast=head; 
	while(Slow!=NULL && Fast!=NULL && Fast->next!=NULL)
	{   Slow = Slow->next;
	    Fast = Fast->next->next; 
	    
        if(Fast==Slow)
        return 1;   }
  
    return 0;	 
}
*/ 
 
int main()
{
    Node *LL = storeLL();      // taking input until -1 is entered ([head]->[node]->[node].......->[node]->[node]->NULL) 

    if(checkCycleInLL(LL))
    cout<<"\nLinked List contains cycle\n\n";  
    else
    cout<<"\nLinked List does not contain cycle\n\n"; 
}























