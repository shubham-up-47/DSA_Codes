#include <bits/stdc++.h>
using namespace std;

 // (string of length n) has (2^n subsequences) 
 
int returnSubsequenses(string str, string *strSubseq)
{
	if(str.size()==0)
    {  strSubseq[0] = str;
       return 1;   }	
	
	int n = returnSubsequenses(str.substr(1), strSubseq);
	
    for(int i=0; i<n; i++)
	strSubseq[n+i] = str[0] + strSubseq[i];	
	
	return 2*n; 
}


int main()
{
   string str="abc";
   
   string strSubseq[100];
   int n = returnSubsequenses(str, strSubseq);
   
   for(int i=0; i<n; i++)
   cout<<strSubseq[i]<<endl; 
} 


 // subsequenses of "abc" are {" ","c","b","bc","a","ac","ab","abc"} 
 //                                \|/      |            |
 //                [add c in old subseq]   \|/           |
 //                        [add b in old subseq]        \|/
 //                                      [add a in old subseq] 
 








 







