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

void printLL(Node *head)                                                      
{ 
    cout<<"\nLL: ";
	while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}
                                                                                                    
void deleteAlternateNodes(Node *head)
{
	if(head==NULL || head->next==NULL)
	return;
	
	for(Node *t=head; t!=NULL&&t->next!=NULL; t=t->next)
	{  
	    Node *temp = t->next;  
	    t->next = t->next->next; 
        delete temp;   
	} 
}
 
 
int main()
{
    Node *LL = storeLL();                             // storing input numbers (until -1 is entered)  
    
	deleteAlternateNodes(LL);   
	
    printLL(LL);
}


  // 9 9 9 9 9 -1    ->    9 9 9
  
  // 4 5 7 3 2 7 9 7 0 6 7 8 9 -1    ->     4 7 2 9 0 7 9
  
  
  
  





 






