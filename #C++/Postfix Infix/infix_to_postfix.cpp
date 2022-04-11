#include <stdio.h>
#include <ctype.h>
#include <iostream>
                                                                     
#define SIZE 50     
char stack[SIZE];
int top = -1;

/*

Enter Infix Expression: A+B/C+D-E 
Postfix Expression: ABC/+D+E-

                                  
#converting infix(operandThenOperatorThenOperand) to postfix (operandsThenOperator) - 

*print operands as they come

*( stackSize=0 || stackTop='(' ) & currChar=operator   =>    push the operator in stack
*precedence(currChar > stackTop) & currChar=operator   =>    push operator in stack
*precedence(currChar < stackTop) & currChar=operator   =>    print & pop stackTop then check again 
*precedence(currChar < stackTop) & currChar=operator   =>    use associativity rule 
(if associativity R to L)                              =>    push operator in stack
(if associativity L to R)                              =>    print & pop stackTop then push operator in stack

*currChar=')'                                          =>    print & pop all operators until stackTop='(' then pop again 

*/

push(char c)
{   stack[++top]=c;  }
                                                                                       
char pop()
{   return(stack[top--]);  }

int pr(char symbol)                                 // precedence        
{ 
	if(symbol == '^')                               // R to L   
	return(3); 
	else if(symbol == '*' || symbol == '/')         // L to R  
	return(2); 
	else if(symbol == '+' || symbol == '-')         // L to R
	return(1); 
	else
	return(0); 
}


int main()
{
    int i=0, k=0;
    char infix[50], postfix[50], ch, elem;
    
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') 
		push(ch);
        else
            if(isalnum(ch))                                    // storing operands in postfix[]            
			postfix[k++]=ch;
            else                                               // storing operator in postfix[]              
                if( ch == ')')
                {   while( stack[top] != '(')
                    postfix[k++]=pop();
                    
                    elem=pop();   }
                else
                {   while( pr(stack[top]) >= pr(ch) )
                    postfix[k++]=pop();
                    
                    push(ch);   }
    }
    
    while( stack[top] != '#')
    postfix[k++]=pop();
    
    postfix[k]='\0';
    printf("\nPostfix Expression: %s\n",postfix);
}
        









 
