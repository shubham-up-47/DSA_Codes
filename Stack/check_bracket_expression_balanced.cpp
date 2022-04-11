#include <bits/stdc++.h>
using namespace std;

//  (()()())=balanced      ()()(()=unbalanced       )()=unbalanced       )(=unbalanced       ()()=balanced

//        [a+{b+(c)}] -> [{()}]=balanced          [a+{b+(c)]} -> [{()]}=unbalanced
                         
bool isBracketExpressionBalanced(string str)
{
	if(str[0]==')' || str[0]=='}' || str[0]==']')
	return 0;
	
	char a,b;
	stack<char> s;                                    // inbuilt stack                          
	for(int i=0; i<str.size(); i++)
	{ 	
	    if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		s.push(str[i]);
		else if(str[i]==')' || str[i]=='}' || str[i]==']')
		{  a = s.top();
		   b = str[i];
		   
		   if((a=='('&&b==')') || (a=='{'&&b=='}') || (a=='['&&b==']')) 
		   s.pop(); 
		   else
		   return 0;	}
    } 
	                                                                                                                       
	return s.empty();
}

 
int main()
{ 
   string str="[{()]}";

   if(isBracketExpressionBalanced(str))
   cout<<str<<": balanced expression of brackets"<<endl; 
   else
   cout<<str<<": unbalanced expression of brackets"<<endl; 
}












