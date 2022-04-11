#include <bits/stdc++.h>
using namespace std;
                                                               
//          Contains redundant bracket = a+(b), (a+b()), ((a+b)) 
//   Doesn't contain redundant bracket = (a+b)+c, (a+b), a+b+c, (c+(a+b))
                                                                                                                                 
bool isRedundantBracketPresent(string str)               // checking (redundant bracket) in given (balanced bracket expression)                             
{
    stack<char> s;

	for (int i=0; i<str.size(); i++) 
	{  
	    if(str[i] == ')')                                // for bracket pair i.e. (...), whose data stored at top of stack  
		{   int c; 
			for(c=0;  !s.empty() && s.top()!='(';  c++)  // counting no of elements in current bracket pair i.e. (...)
		    s.pop();   
            s.pop();                                     // removing ')'
 
			if(c < 2)
			return 1;   }                                // ()  or (x)  case 
	    else
		s.push(str[i]);                                  // storing "data of bracket pair i.e. (...)" in stack until a "bracket end i.e. ) comes" 
	}
	 
	return 0;
}
 
 
int main()
{ 
   string str="((a+b)+c)";

   if(isRedundantBracketPresent(str))
   cout<<str<<": contains redundant brackets"<<endl; 
   else
   cout<<str<<": doesn't contain redundant bracket"<<endl; 
}












 
