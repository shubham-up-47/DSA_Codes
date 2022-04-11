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
                                                                                         
Node* skipMdeleteN_nodesWhileLLtraversal(Node *head, int M, int N)                 
{
	if(M==0)
	return NULL;
	else if(N==0)
	return head;
 
 
	for(Node *t=head;  t!=NULL;  t=t->next)
	{ 
   	   for(int i=1;  i<M && t->next!=NULL;  i++,t=t->next);      // skip M
   	   
	   for(int i=1;  i<=N && t->next!=NULL;  i++)                // delete N
       {  Node *np = t->next;
          t->next = t->next->next; 
          delete np;  }      
	}
	
	
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
	int M=3, N=2;
    Node *LL = storeLL();                                        // storing input number (until -1 is entered)  
 
    LL = skipMdeleteN_nodesWhileLLtraversal(LL, M, N);
                                    
    printLL(LL);
	cout<<endl<<endl;
}

 
//  0 2 8 1 3 7 5 7 6 4 9 -1    
  
  
  
  





