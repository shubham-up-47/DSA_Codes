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

Node* reverseLL(Node *head)
{ 
	Node *preN=NULL, *currN=head;
	
	while(currN!=NULL)
	{  Node *postN = currN->next;
	
	   currN->next = preN;                                   // from [preN]->[currN] to [preN]<-[currN]
	 
	   preN = currN;
	   currN = postN;  }
	
	return preN; 
}
                                                                 
Node* findMidNodeLL(Node *head)
{
    int n=0; 
	for(Node *t=head;  t!=NULL;  t=t->next,n++);
	
	Node *midN=head; 
	for(int i=0;  i<(n-1)/2;  midN=midN->next,i++);          // loop runs till [(n-1)/2]th index of LL
	
	return midN;	 
}
	                                                                                        
bool isLLPalindrome(Node *head)
{
	if(head==NULL || head->next==NULL)
	return head;


    Node *head1 = head;
	Node *midN = findMidNodeLL(head);   
	Node *head2 = reverseLL(midN->next); 
	
	while(head2 != NULL)
	{   if(head1->data != head2->data)
        return 0;
        
	    head1 = head1->next; 
        head2 = head2->next;   }
   
   
    return 1;	 	 
}
 
 
int main()
{
    Node *LL = storeLL();                                    // storing input numbers (until -1 is entered)  
 
    if(isLLPalindrome(LL))
	cout<<"\nInput LL is a palindrome"<<endl;
	else   
	cout<<"\nInput LL is not a palindrome"<<endl;
}

 
 //  0 2 3 4 6 7 7 6 4 3 2 0 -1    
  
  
  
  
   




