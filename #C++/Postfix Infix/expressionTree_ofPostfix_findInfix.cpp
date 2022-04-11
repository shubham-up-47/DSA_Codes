#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
                         
struct Node                             // storing BinaryTreeNode  
{
    char data;
    Node *left, *right;
 
    Node(char data)
    {
        this->data = data;
        this->left = nullptr;
		this->right = nullptr;
    };
 
    Node(char data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    };
};
                         
                         
bool isOperator(char c)                        // check given char is an operator or not 
{   return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');   }
  

void inorder(Node* root)                       // printing infix expression pf expression tree
{
    if(root==nullptr)
    return;
 

    if(isOperator(root->data))                  // if current char is an operator then print open parenthesis
    cout << "(";
 
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
  
    if(isOperator(root->data))                 // if current char is an operator then print close parenthesis
    cout << ")";
}
 

Node* construct(string postfix)                // constructing expression tree of given postfix expression
{
    if(postfix.length()==0)
    return nullptr;
 

    stack<Node*> s;                           // stack storing tree pointers
  
    for(char c: postfix)                      // traversing postfix expression
    { 
        if (isOperator(c))                    // if the current char is an operator
        {   Node* x = s.top();
            s.pop();
 
            Node* y = s.top();
            s.pop();
  
            Node* node = new Node(c, y, x);         // SubBinaryTree whose (root=operator, left child = y, right child = x) 
            s.push(node);   }
            
        else                                        // if the current char is an operand
        s.push(new Node(c));                        // SubBinaryTree whose (root=operand)  
    }
 

    return s.top();                               // returning root pointer of expression tree 
}
 
int main()
{ 
    cout<<"Enter Postfix Expression: ";
    
    string postfix;
    cin>>postfix; 
    cout<<endl;  
    
    
    cout << "\nInfix Expression of Input Postfix Expression: "; 
    Node* root = construct(postfix);            
    inorder(root); 
    cout<<endl; 
}


/*

xy+pqr+**                    

*/










