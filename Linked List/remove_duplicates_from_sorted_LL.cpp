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
    cout<<"\nLL after removing duplicates: ";
	while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}
             
				                                                                                        
Node* removeDuplicateFromSortedLL(Node *head)
{
	if(head==NULL || head->next==NULL)
	return head;
	
	
	Node *t1 = head;
	Node *t2 = head->next;
	
	while(t1!=NULL && t2!=NULL)
	{
	    if(t1->data == t2->data)
        {   t1->next = t2->next;
            t2 = t1->next;   }
	    else
        {   t1 = t1->next; 
            t2 = t2->next;   }
    }
  
  
    return head;	 	 
}
 
 
int main()
{
    Node *LL = storeLL();                             // storing input number (until -1 is entered)  
 
    LL = removeDuplicateFromSortedLL(LL);   
    printLL(LL);
}

 
 //  0 2 3 4 6 7 7 7 7 8 9 9 -1    
  
  
  
  
   







