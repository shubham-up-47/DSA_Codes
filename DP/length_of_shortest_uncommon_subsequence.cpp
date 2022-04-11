#include <bits/stdc++.h>            
using namespace std;
                                                                                              
#define INT_MAX 1000
                                                                                
// finding length of (shortest uncommon subsequence for given 2 strings), which is in 1st string & not in 2nd string 
// arr[i][j] = length of shortest uncommon subsequence when (i = s.size()) & (j = t.size())
// s = "babab",  v = "babba"       =>       "aab" is shortest uncommon subsequence
// total subsequences of s = 2^n, so BruteForce sol is very time taking
                                                                         
int lastCharOf_S_in_V(string s, string t, int m, int n) 
{
   char c = s[m-1];	
                       
   for(int i=n-1;  i>=0;  i--)
   {  if(t[i]==c)
   	  return i;  }
   
   return -1;	
}
                                                                                               
int lengthOfShortestUncommonSubsequenceBF(string s, string t)                                   // Brute Force { O(2^x) where x=max(m,n) } 
{ 
	int i=s.size(), j=t.size(); 

	if(i==0)       
	return INT_MAX;
	else if(j==0)       
	return 1;
	      
		            	                                                                                                                    
	int x = lastCharOf_S_in_V(s,t,i,j), r;                                                  
	if(x==-1) 
	r = 1;                                                                                      // a char is in 's' but not in 't', so (ans = 1)                           
    else
    {   int r1 = 1 + lengthOfShortestUncommonSubsequenceBF(s.substr(0,i-1), t.substr(0,x));     // including s[n-1]               
    	int r2 = lengthOfShortestUncommonSubsequenceBF(s.substr(0,i-1),t);                      // excluding s[n-1]
	    r = min(r1, r2);   }
	  
	                   
	return r;
}
                                                                                                                                            
int lengthOfShortestUncommonSubsequenceM(string s, string t, int **arr)                         // Memorization { O(m*n) }
{
	int i=s.size(), j=t.size();    
	   
	if(i==0)       
	return INT_MAX;
	else if(j==0)       
	return 1;
	else if(arr[i][j] != -1)
	return arr[i][j];
	                                                                             
	                                                                       
	int x = lastCharOf_S_in_V(s,t,i,j);
	if(x==-1) 
	arr[i][j] = 1;                                                                              // a char is in 's' but not in 't', so (ans = 1)                             
    else
    {   int r1 = 1 + lengthOfShortestUncommonSubsequenceM(s.substr(0,i-1), t.substr(0,x), arr); // including s[n-1]               
    	int r2 = lengthOfShortestUncommonSubsequenceM(s.substr(0,i-1), t, arr);                 // excluding s[n-1]
	    arr[i][j] = min(r1, r2);   }
	                                                                                  
		                                                                              
	return arr[i][j]; 
}
                                                                                         
                                                                                                                            
int main()
{
	string s="babab", t="babba";
	int m=s.size(), n=t.size();
	cout<<"Length of shortest uncommon subsequence in '"<<s<<"' but not in '"<<t<<"' is:"<<endl;
                                                      
													           	
    cout<<lengthOfShortestUncommonSubsequenceBF(s, t)<<endl;
    
                                         	
	int **arr1 = new int*[m+1];
	for(int i=0; i<m+1; i++)
	{   arr1[i] = new int[n+1]; 
	    for(int j=0; j<n+1; j++)
	    arr1[i][j] = -1;    }
    cout<<lengthOfShortestUncommonSubsequenceM(s, t, arr1)<<endl; 
                    
                    
    int **arr2 = new int*[m+1];                                                                 // Dynamic Programming { O(m*n) }
	for(int i=0; i<m+1; i++)
	arr2[i] = new int[n+1]; 
	                                                             
	arr2[0][0] = INT_MAX;
	for(int i=1; i<m+1; i++)
	arr2[i][0] = 1; 
	for(int j=1; j<n+1; j++)
	arr2[0][j] = INT_MAX; 
	
	for(int i=1; i<m+1; i++)
	{   for(int j=1; j<n+1; j++)
        {	
            int x = lastCharOf_S_in_V(s,t,i,j);
        	if(x==-1) 
        	arr2[i][j] = 1;                                                                     // a char is in 's' but not in 't', so (ans = 1)                             
            else
            {  int r1 = 1 + arr2[i-1][x];                                                       // including s[n-1]               
               int r2 = arr2[i-1][j];                                                           // excluding s[n-1]
        	   arr2[i][j] = min(r1, r2);  } 
		}
    }
    cout<<arr2[m][n]<<endl; 
}
           
                                    
 




 
 
 
 
  
