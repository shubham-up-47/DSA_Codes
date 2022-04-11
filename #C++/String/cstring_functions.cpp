#include <bits/stdc++.h>
using namespace std;
 

int main()
{
   char name[20] = {'a','n','t'}, temp[20];
   
   
   cout<<strlen(name)<<endl;                  // returns length of string, so NULL char is excluded  
    
   cout<<strcmp(name,name)<<endl;             // returns difference of ASCII values of first non matching chars of string1 & string2          

   strcpy(name, "fish");                      // copies second string to first string
   cout<<name<<endl;
   
   strncpy(name, "ramanujan", 5);             // copies first 5 char of second string to first string
   cout<<name<<endl;
}












 
















