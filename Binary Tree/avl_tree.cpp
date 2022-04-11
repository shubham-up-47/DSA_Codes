#include<bits/stdc++.h>
using namespace std;


/*

AVL Tree
*BST
*Balanced BT

*/


class Node                          // AVL TreeNode
{
   	    public:
	int key;
	Node *left;
	Node *right;
	int height;
};
 
                              
int height(Node *N)                // returning height of current AVL tree   
{
	if(N==NULL)
	return 0;
	
	return N->height;
}
 
              
Node* newNode(int k)              // creating new node as leaf node (key=k, left=NULL, right=NULL, height=1) 
{
	Node* node = new Node();
	node->key = k;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	
	return node;
}


Node *rightRotate(Node *y)              // right rotation of subtree rooted with "y" 
{
	Node *x = y->left;
	Node *T2 = x->right;


	x->right = y;                                             	    // perform rotation
	y->left = T2;
          
	y->height = max(height(y->left), height(y->right)) + 1;        	// update heights 
	x->height = max(height(x->left), height(x->right)) + 1;


	return x;                                	// returning new root
}


Node *leftRotate(Node *x)                         // left rotation of subtree rooted with "x" 
{
	Node *y = x->right;
	Node *T2 = y->left;

 
	y->left = x;                                                  	    // perform rotation
	x->right = T2;
 
	x->height = max(height(x->left), height(x->right)) + 1;            	// update heights 
	y->height = max(height(y->left), height(y->right)) + 1;

 
	return y;                                          	// returning new root
}


int getBalance(Node *N)                                // returning BalanceFactor of node N
{
	if(N==NULL)
	return 0;
	
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{ 
	if(node == NULL)                       
	return newNode(key);

	if(key < node->key)                            	// performing normal BST rotation 
	node->left = insert(node->left, key);
	else if(key > node->key)
	node->right = insert(node->right, key);
	else                                            // equal keys are not allowed
	return node;

	
	node->height = 1 + max(height(node->left), height(node->right));       // updating height of the ancestor node  
	
 
	int balance = getBalance(node);              // get balance factor of the ancestor node & if it is unbalanced, then follow 4 cases  
 
	if(balance > 1 && key < node->left->key)               	// Left Left Case
	return rightRotate(node);
 
	if(balance < -1 && key > node->right->key)            	// Right Right Case
	return leftRotate(node);
 
	if(balance > 1 && key > node->left->key)              	// Left Right Case
	{  node->left = leftRotate(node->left);
	   return rightRotate(node);  }
 
	if (balance < -1 && key < node->right->key)             // Right Left Case
	{  node->right = rightRotate(node->right);
	   return leftRotate(node);  }


	return node;                                           // return the (unchanged) node pointer 
}  


Node* minValueNode(Node* node)                    // returning the node having minimum key in the given BST
{
	Node* current = node;

	while(current->left != NULL)                 // loop down to find the leftmost leaf  
	current = current->left;

	return current;
}


Node* deleteNode(Node* root, int key)                    // recursive function to delete a node from subtree  
{
	if(root == NULL)
	return root;


	if(key < root->key)                                      	// node to be deleted lies in left subtree
	root->left = deleteNode(root->left, key);
    else if(key > root->key)                             	    // node to be deleted lies in right subtree  
	root->right = deleteNode(root->right, key);
    else                                                        // node to be deleted is root of current subtree 
	{
	
		if( (root->left == NULL) || (root->right == NULL) )         	// node with 1 child or 0 child
		{
			Node *temp = root->left ? root->left : root->right;

			if (temp == NULL)                                           // no child case
			{   temp = root;
				root = NULL;  }
			else                                                        // one child case
			*root = *temp;                                              // copy the contents of the non-empty child
			free(temp);
		}
		else                                  // node with 2 children
		{ 
			Node* temp = minValueNode(root->right);                    // get the inorder successor (smallest in the right subtree)
 
			root->key = temp->key;                           			// Copy the inorder successor's data to this node

			root->right = deleteNode(root->right, temp->key);          	// delete the inorder successor
		}
	}

 
	if (root == NULL)                                 	// subtree has only one node
	return root;


	root->height = 1 + max(height(root->left), height(root->right));   	// update height of current node

 
	int balance = getBalance(root);                      // get balance factor of the node & if it is unbalanced, then follow 4 cases  
 
	if(balance > 1 && getBalance(root->left) >= 0)                 	// Left Left Case
		return rightRotate(root);

    if(balance > 1 && getBalance(root->left) < 0)                        	// Left Right Case
	{   root->left = leftRotate(root->left);
		return rightRotate(root);	}
 
	if(balance < -1 && getBalance(root->right) <= 0)                           	// Right Right Case
	return leftRotate(root);
 
	if(balance < -1 && getBalance(root->right) > 0)                              	// Right Left Case
	{	root->right = rightRotate(root->right);
		return leftRotate(root);	}


	return root;                           // returning root of modified AVL tree.
}
 
 
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node *root)
{
	if(root != NULL)
	{
		preOrder(root->left);
		cout << root->key << " ";
		preOrder(root->right);
	}
}

void postOrder(Node *root)
{
	if(root != NULL)
	{
		preOrder(root->left);
		preOrder(root->right);
		cout << root->key << " ";
	}
}

 
int main()
{
    Node *root = NULL; 
    
	root = insert(root, 12);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 10);
	root = insert(root, 2);
	root = insert(root, 11);
	root = insert(root, 5);
	root = insert(root, 6);
 
	cout << "\nPreorder traversal AVL tree is: \n";
	preOrder(root);
	cout << "\nInorder traversal AVL tree is: \n";
	inOrder(root);
	cout << "\nPostorder traversal AVL tree is: \n";
	postOrder(root);

	root = deleteNode(root, 8);
	root = deleteNode(root, 5);
 
	cout << endl;
 
	cout << "\nPreorder traversal of AVL tree after deletion of 8,5 is: \n";
	preOrder(root);
	cout << "\nInorder traversal of AVL tree after deletion of 8,5 is: \n";
	inOrder(root);
	cout << "\nPostorder traversal of AVL tree after deletion of 8,5 is: \n";
	postOrder(root); 
	
	cout << endl;
}
 
 
/*

Considering 

January = 1
February = 2
March = 3
April = 4
May = 5
June = 6
July = 7
August = 8
September = 9
October = 10
November = 11
December = 12

*/






