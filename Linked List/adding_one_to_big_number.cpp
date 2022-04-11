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
    cout<<"LL: ";
	while(head != NULL)
	{  cout<<head->data<<" ";
       head = head->next;  }
    cout<<endl;
}
 
int carryAfterAddingOne(Node *n)
{
    if(n==NULL)                                         // adding 1 on unit digit
	return 1; 
	
	
	int sum = n->data + carryAfterAddingOne(n->next);   // adding data + carry (dataOfCurrentNode + carryOnCurrentNode) 
 
 	n->data = sum%10;                                   // storing newData (unitDigitOfSum) in currntNode 
	int nextCarry = sum/10;                             // returning nextCarry (tenthDigitOfSum) for nextNode 
	
	
	return nextCarry;                                      
} 
                                                                                                        
Node* addingOneToBigNumber(Node *head)
{
	if(head==NULL)
	return head;
	
	
	int finalCarry = carryAfterAddingOne(head);
	
	if(finalCarry != 0)
	{   Node *np = new Node(finalCarry);
	    np->next = head;
        head = np;   }
  
  
    return head;	 	 
}
 
 
int main()
{
    Node *LL = storeLL();                               // storing input number (until -1 is entered)  
 
    LL = addingOneToBigNumber(LL);   
    printLL(LL);
}


  // 9 9 9 -1    ->    1 0 0 0
  
  // 4 5 7 3 2 7 9 7 0 6 7 8 9 -1    ->     4 5 7 3 2 7 9 7 0 6 7 9 0
  
  
  
  
  
  
   


