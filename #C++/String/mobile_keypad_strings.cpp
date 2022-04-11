#include <bits/stdc++.h>
using namespace std;

 // storing all (n length strings) from given (n digit number) using (chars on keypad corresponding to each digit)
 
string keypadChar[10];
  
int returnKeypadStrings(int n, string *strKeypad)
{
	if(n==0)
	{  strKeypad[0] = "";
	   return 1;  }
	   
	
	string strTemp[100];
	int nT = returnKeypadStrings(n/10, strTemp); 
	int d = n%10;
	int nC = keypadChar[d].size();
	
    for(int i=0; i<nC; i++)
	{  for(int j=0; j<nT; j++)
       { 
		  strKeypad[i*nT + j] = keypadChar[d][i] + strTemp[j];
       }
	}
	
 
	return nC*nT; 
}
              

int main()
{                            keypadChar[2] = "abc";  keypadChar[3] = "def";  
	keypadChar[4] = "ghi";   keypadChar[5] = "jkl";  keypadChar[6] = "mno";
	keypadChar[7] = "pqrs";  keypadChar[8] = "tuv";  keypadChar[9] = "wxyz";
	
    int n = 27;
    string strKeypad[100];
    int nK = returnKeypadStrings(n, strKeypad);
    
    for(int i=0; i<nK; i++)
	cout<<strKeypad[i]<<endl; 
}











 







