#include <bits/stdc++.h>
using namespace std;

 // returning all n! (n size permutations) of given (n size string)                                       

int returnStringPermutations(string str, string strPermut[])                // method 1       
{
	if(str.size()==0)
	{  strPermut[0] = "";
	   return 1;  }
	
    string strTemp[1000];
	int nT = returnStringPermutations(str.substr(1), strTemp);
	int n = 0;
 
	for(int i=0; i<nT; i++)
	{  for(int j=0; j<=strTemp[i].size(); j++,n++)                          // dont forget "=" case, bcz then (suffix size=max) & (prefix size=0) 
       {
	      strPermut[n] = strTemp[i].substr(0,j) + str[0] + strTemp[i].substr(j);
       } 
	}
	
	return n; 
}
 
void swap(string s, int i, int j) 
{
  	char temp = s[i];
	s[i] = s[j];
	s[j] = temp; 
}
         
int returnPermutations(string s, string t[], int si, int ei, int n=0)       // method 2         
{ 
	if(si==ei)                    
    return 0;  
	 
    for(int i=si; i<=ei; i++,n++)    
	{   swap(s,si,i);
	      
	    t[n]=s;
	    int r = returnPermutations(s, t, si+1, ei, n);      
	        
	    swap(s,si,i);	} 	
	   
	return n;                       
} 

int main()
{
   string str="abc";

   string strPermut[1000];
   int n = returnStringPermutations(str, strPermut);
   
   for(int i=0; i<n; i++)
   cout<<strPermut[i]<<endl; 
} 

























