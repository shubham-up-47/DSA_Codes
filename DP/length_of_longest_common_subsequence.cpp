#include <bits/stdc++.h>
using namespace std;
                                    
// finding length of (longest common subsequence for given 2 strings), whose char occur in same order as in input strings
// arr[i][j] = length of longest common subsequence when (i = s.size()) & (j = t.size())
                                                                             
int lengthOfLongestCommonSubsequenceBF(string s, string t)                                // Brute Force { O(2^x) where x=max(m,n) } 
{
	if(s.size()==0 || t.size()==0)       
	return 0;
	 
	int r;
	if(s[0]==t[0])
	r = 1 + lengthOfLongestCommonSubsequenceBF(s.substr(1), t.substr(1));                 // including s[0] & t[0]            
    else
    {   int r1 = lengthOfLongestCommonSubsequenceBF(s.substr(1), t);                      // excluding s[0]
    	int r2 = lengthOfLongestCommonSubsequenceBF(s, t.substr(1));                      // excluding t[0]
	    r = max(r1, r2);   }
	                      
	return r;
}
                                                           
int lengthOfLongestCommonSubsequenceM(string s, string t, int **arr)                      // Memorization { O(m*n) }
{
	int i=s.size(), j=t.size();    
	   
	if(i==0 || j==0)
	return 0;
	else if(arr[i][j] != -1)
	return arr[i][j];
	 
	if(s[0]==t[0])
	arr[i][j]= 1 + lengthOfLongestCommonSubsequenceM(s.substr(1), t.substr(1), arr);      // including s[0] & t[0]            
    else
    {   int r1 = lengthOfLongestCommonSubsequenceM(s.substr(1), t, arr);                  // excluding s[0]
    	int r2 = lengthOfLongestCommonSubsequenceM(s, t.substr(1), arr);                  // excluding t[0]
	    arr[i][j] = max(r1, r2);   }
	                      
	return arr[i][j];
}
                                         
                                                                                                   
int main()
{
	string s="abcde", t="cadbe";
	int m=s.size(), n=t.size();
	cout<<"Length of longest common subsequence for strings "<<s<<" & "<<t<<" is:"<<endl;
                                                      
													           	
    cout<<lengthOfLongestCommonSubsequenceBF(s, t)<<endl;
    
                                         	
	int **arr1 = new int*[m+1];
	for(int i=0; i<m+1; i++)
	{   arr1[i] = new int[n+1]; 
	    for(int j=0; j<n+1; j++)
	    arr1[i][j] = -1;    }
    cout<<lengthOfLongestCommonSubsequenceM(s, t, arr1)<<endl; 
                    
                    
    int **arr2 = new int*[m+1];                                                           // Dynamic Programming { O(m*n) }
	for(int i=0; i<m+1; i++)
	arr2[i] = new int[n+1]; 
	 
	arr2[0][0] = 0;
	for(int i=1; i<m+1; i++)
	arr2[i][0] = 0; 
	for(int j=1; j<n+1; j++)
	arr2[0][j] = 0; 
	
	for(int i=1; i<m+1; i++)
	{   for(int j=1; j<n+1; j++)
        {	
		    if(s[m-i]==t[n-j])
            arr2[i][j] = 1 + arr2[i-1][j-1]; 
     	    else
    	    arr2[i][j] = max(arr2[i-1][j], arr2[i][j-1]);    
		}
    }
    cout<<arr2[m][n]<<endl; 
}
           
                                    
 






