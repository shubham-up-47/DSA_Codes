#include <bits/stdc++.h>
using namespace std;
 
 // STORING FREUENCY OF CHAR
 
bool checkPermutation(char s1[], char s2[])       // checking that one string can be permuted to give other or not 
{
   int f1[256]={0}, f2[256]={0}, i, j;
    
   for(i=0,j=0; s1[i]!=0||s2[j]!=0; )	          // storing frequency of char
   {  if(s1[i]!=0)
   	  {  f1[s1[i]]++;
   	     i++;  }	
	
	  if(s2[j]!=0)
   	  {  f2[s2[j]]++;
   	     j++;  }    }
    
   for(i=0; i<256&&f1[i]==f2[i]; i++);
   
   return (i==256); 
 } 
 

int main()
{

 





}













