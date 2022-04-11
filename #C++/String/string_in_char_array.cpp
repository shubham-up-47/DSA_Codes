#include <bits/stdc++.h>
using namespace std;


int lengthOfString_in_charArray(char *arr)
{
  int i; 
  for(i=0; arr[i]!='\0'; i++);	
  return i;
}


void reverseString(char *arr)
{
  if(arr[0]=='\0')
  return;	
	 
  int i,j;  
  for(j=0; arr[j+1]!='\0'; j++);
  	 
  for(i=0; i<j; i++,j--)
  {  char temp=arr[i];
     arr[i]=arr[j];
     arr[j]=temp;   } 
}


int main()
{
    char name[20] = {'a','n','t'}; 
    cout<<lengthOfString_in_charArray(name)<<endl;  
    reverseString(name);
    cout<<name<<endl;
   
    
	char b[] = "abc";                                        // (char array of size 4) is created where last char is NULL 
	cout<<b<<"  "<<&b[0]<<"  "<<&b[1]<<endl;                 // it will keep printing till it finds a NULL char   
	cout<<b[0]<<"  "<<b[1]<<"  "<<b[2]<<endl;                // each will print a char 
	 
	char c = 'a'; 
	cout << &c << endl;                                      // it will keep printing till it finds a NULL char 
	
	char s[] = "abcde";                                      // (char array of size 6) is created 
	char *sp = "abcde";                                      // pointer points to (temporary char array of size 6) created   
}








 
 

