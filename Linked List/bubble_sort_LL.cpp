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
 
int sizeLL(Node *head)
{
    int c;
	for(c=0;  head!=NULL;  head=head->next,c++);
	return c;	 
}

void swapN(Node* &head, Node* &preN, Node* &currN, Node* &postN)
{
	if(currN==head)                                         // from [currN]->[postN] to [postN]->[currN]
	{	currN->next = postN->next;
   	  	postN->next = currN;  
			
		head = postN;
					   
		Node *t = currN;
		currN = postN;
		postN = t;   }
	else	                                                // from [preN]->[currN]->[postN] to [preN]->[postN]->[currN]
	{  	preN->next = postN;
	    currN->next = postN->next;
   	  	postN->next = currN;   
			              
		Node *t = currN;
		currN = postN;
		postN = t;    }                                     // moving preN & currN by one unit 
}
 
Node *bubbleSortLL(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
   
   
    int n = sizeLL(head);
     
    for(int i=0; i<n; i++)
    {   Node *preN=NULL, *currN=head;
    	
   	    for(int j=0; j<n-i; j++)
   	    { 	Node *postN = currN->next; 
   	    	
   	  	    if(postN!=NULL && (currN->data)>(postN->data))  // swap if arr[i] > arr[i+1]
   	  	    swapN(head, preN, currN, postN);
			    
			preN = currN;
			currN = postN;    
		}
   }
   	
   return head;
}


int main()
{
    Node *LL = storeLL();                                   // taking input till -1 is entered   

    cout<<"\nSize of LL: "<<sizeLL(LL)<<endl; 
    printLL(LL); 
    LL = bubbleSortLL(LL);
    printLL(LL);  
}

















