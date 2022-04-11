#include <bits/stdc++.h>
using namespace std;

// returning all (string codes) from given number when ('a'=1, 'b'=2 ........ 'y'=25, 'z'=26)                                     
  
int returnStringCodes(string str, string strCode[])
{
	if(str.size()==0)
	{  strCode[0] = "";
	   return 1;  }
             
             
 	int n=0, n1, n2;   
	string strTemp1[1000], strTemp2[1000];       	
	char c1=(str[0]-48)+96, c2=((str[0]-48)*10 + (str[1]-48))+96;      // c'i' = char code made using 'i' digits of number string
 
 	if(c1>=96 && c1<=105)                                              // a to j
    {   n1 = returnStringCodes(str.substr(1), strTemp1);
    	for(int i=0; i<n1; i++,n++)
    	strCode[n] = c1 + strTemp1[i];   }
 
 	if(c2>=106 && c2<=132)                                             // k to z
    {   n2 = returnStringCodes(str.substr(2), strTemp2);
    	for(int i=0; i<n2; i++,n++)
    	strCode[n] = c2 + strTemp2[i];   }
    	                                                           
              
	return n; 
}
   
   
int main()
{ 
   int x = 1123;
   stringstream ss;
   ss<<x;
   string s = ss.str();
   
   string strCode[1000];
   int n = returnStringCodes(s, strCode);
   
   for(int i=0; i<n; i++)
   cout<<strCode[i]<<endl; 
} 










 




 
