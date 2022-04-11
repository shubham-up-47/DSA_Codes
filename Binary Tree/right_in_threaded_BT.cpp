#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node
{
    int data;
    struct Node *left;
	struct Node *right;
    bool rThread;
};                                                             
                                              
void makeRightInThreadedBT(struct Node *root, int item)
{
    root->data = item;
    root->left = root->right = NULL;
}
                                                                                                                                              
void setLeft(struct Node *p, int item)
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	
    temp->data = item; 
    temp->left = NULL; 
    temp->right = p;
    temp->rThread = 1; 
    
	p->left = temp;
}                                                  
                                                                                                                                                                         
void setRight(struct Node *p, int item)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));                            
    
    temp->data = item;                         
    temp->left = NULL;                         
    temp->right = p->right;                    
    temp->rThread = 1;                       
                                                                                                   
    p->right = temp;                           
    p->rThread = 0;                              
}
                                                                
void threadInorder(struct Node *temp)
{
    while(temp != NULL)
    {
        while(temp->left != NULL)
        temp = temp->left;
        
        printf("%d  ", temp->data);
        if(temp->rThread == true && temp->right!=NULL)
        {  temp = temp->right;
           printf("%d  ", temp->data);  }
                                                                                                       
        temp = temp->right;                                  
    }                                                                 
}
  
                                         
int main()
{
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    
    if(root==NULL)
    printf("Given Right In Threaded BT has no nodes");
    
    root->data = 1;
    makeRightInThreadedBT(root, 15); 
                                         
    setLeft(root, 5);                                                  
    setRight(root, 7);

    setLeft(root->left, 10); 
    setRight(root->left, 20);

    setLeft(root->right, 30); 
    setRight(root->right, 9);                                            
                                                                      
    setRight(root->right->left, 3);                                              

    printf("Printing Inorder of Right In Threaded Tree: \n");
    threadInorder(root);
    printf("\n\n\n"); 
}

 
/*                                     
                                                                                                                      
        15                                      
        /\                                     
       /  \                        
      /    \
     5      7
    /\      /\
   /  \    /  \
  /    \  /    \
10    20 30     9
         /
        /
       /
      3 
  
*/                                                   
                                                                     
            






