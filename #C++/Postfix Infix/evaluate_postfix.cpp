#include<stdio.h>
#include <stdlib.h> 
#include <iostream> 
 
int stack[20];
int top = -1;

/*

#Evaluate postfix expression -          

Infix Expression: 5+4/2+3-1   

Postfix Expression: 542/+3+1-  =  5+2+2  =  9   
  
*/
 
void push(int x)
{   stack[++top] = x;  }

int pop()
{   return stack[top--];  }


int main()
{
    char str[20];
    char *e;
    
    int n1, n2, n3, num;
    printf("Enter the expression: ");
    scanf("%s",str);
    
    e = str;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {   num = *e - 48;
            push(num);  }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {   n3 = n1 + n2;
                break;  }
            case '-':
            {   n3 = n2 - n1;
                break;  }
            case '*':
            {   n3 = n1 * n2;
                break;  }
            case '/':
            {   n3 = n2 / n1;
                break;  }
            }
            push(n3);
        }
        e++;
    }
    
    printf("\nThe result of expression %s  =  %d\n\n",str,pop());
    return 0;
}








