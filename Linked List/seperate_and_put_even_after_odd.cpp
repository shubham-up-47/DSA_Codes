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
                                                                                         
Node* seperateAndPutEvenAfterOdd(Node *head)                  // keep the relative order of even & odd same
{
	if(head==NULL || head->next==NULL)
	return head;
 
	Node *headE=NULL, *tailE=NULL;                            // LL of even numbers
	Node *headO=NULL, *tailO=NULL;                            // LL of odd numbers
	  
	for(Node *t=head; t!=NULL; t=t->next)
	{  if(t->data % 2 == 0)
       addElementInLL(t, headE, tailE);
       else
       addElementInLL(t, headO, tailO);   }
        
    if(headO==NULL)                                           // no odd numbers
	{  tailE->next = NULL;
	   return headE;  } 
	else if(headE==NULL)                                      // no even numbers
	{  tailO->next = NULL;
	   return headO;  }
	else                                                      // both odd & even are present in LL    
	{  tailO->next = headE;
	   tailE->next = NULL;
	   return headO;  }	 	 
}


void printLL(Node *head)                                                      
{ 
    cout<<"\nLL after putting even after odd: ";
	while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}
                   
 
int main()
{
    Node *LL = storeLL();                                     // storing input number (until -1 is entered)  
 
    LL = seperateAndPutEvenAfterOdd(LL);
                                    
    printLL(LL);
	cout<<endl<<endl;
}

 
//  0 2 8 1 3 7 7 6 4 9 -1    
  
  
  
  
   






