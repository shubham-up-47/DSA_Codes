#include <bits/stdc++.h>
using namespace std;


bool checkPalindromeString(string s)
{ 
	for(int i=0,j=s.size()-1; i<=j; i++,j--)
	{  if(s[i] != s[j])
	   return 0;  }
	
	return 1;
}


int main()
{ 
   cout<<checkPalindromeString("shubuhs");	  
}























