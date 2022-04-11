#include <bits/stdc++.h>
using namespace std;


bool isOperand(char x) {
   return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}


string infixConversion(string postfix) {
   stack<string> infix;
   for (int i=0; postfix[i]!='\0'; i++) {
      if (isOperand(postfix[i])) {
         string op(1, postfix[i]);
         infix.push(op);
      } else {
         string op1 = infix.top();
         infix.pop();
         string op2 = infix.top();
         infix.pop();
         infix.push("{"+op2+postfix[i]+op1 +"}");
      }
   }
   return infix.top();
}


int main() {
   string postfix = "AB-C+DEF-+$";                 // don't keep space
   cout<<"The infix conversion of the postfix expression '"<<postfix<<"' is : ";
   cout<<infixConversion(postfix);
   return 0;
}






