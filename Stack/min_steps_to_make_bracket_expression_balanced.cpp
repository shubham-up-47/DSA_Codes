#include <bits/stdc++.h>
using namespace std;

//      {{ = 1             {{{{}} = 1               {{{ = can't balanced bcz odd no of brackets   
//     }{{{ = 3              }{ = 2
                         
int minStepsToMakeBracketExpressionBalanced(string str)
{
	if(str.size()%2 != 0)     // balacing done if [ total brackets(even) = no of balanced brackets(even) + no of unbalanced brackets(even) ]
	return -1;
	 
	stack<char> s;                                                    // inbuilt stack                          
 	for(int i=0; i<str.size(); i++)
	{  
	    if(str[i]=='}')
		{  	if( (s.size()==0) || (s.size()>0 && s.top()=='}') )       //  }  or  }}  case
	    	s.push(str[i]);
		    else if(s.size()>0 && s.top()=='{')                       //  {}  case
		    s.pop();   }
	    else if(str[i]=='{')                                          //  {  or {{ or  }{  case
		s.push(str[i]);    
	}
  
/*
	for(int i=0; i<str.size(); i++)                                   // but this code will not ignore (elements present between brackets)         
	{  
	    if(s.size()>0 && s.top()=='{' && str[i]=='}')
		s.pop();   
	    else                                       
		s.push(str[i]);    
	}
*/		
		 
	int count=0, l=s.size();                                          // s.size() = no of unbalanced brackets(even) 
	for(int i=0; i<l/2; i++)	
	{   
	    char b1 = s.top();      s.pop();
	   	char b2 = s.top();      s.pop();
		
		if(b1==b2)                                                    //  {{  or  }}  or  {{  case
		count += 1;
		else                                                          //  }{  case
		count += 2;	   
	}
                                                                                                                                                                 
	return count;
}

 
int main()
{ 
   string str="}{{{";
 
   cout<<"\nMin no. of brackets reversed to make "<<str<<" balanced: "<<minStepsToMakeBracketExpressionBalanced(str)<<endl; 
}


















