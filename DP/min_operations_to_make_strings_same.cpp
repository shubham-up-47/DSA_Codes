#include <bits/stdc++.h>
using namespace std;
                                    
// finding min no of operations (insertChar/removeChar/replaceChar) applied on string 2, to make both input strings same  [Edit Distance]
// arr[i][j] = min operation done to equalize strings when (i = s.size()) & (j = t.size())
                                                                             
int minOperationsToMakeStringsSameBF(string s, string t)                                  // Brute Force { O(3^x) where x=max(m,n) } 
{
	if(s.size()==0 || t.size()==0)       
	return max(s.size(), t.size());
	           
			                                     
	int r;
	if(s[0] == t[0])
	r = minOperationsToMakeStringsSameBF(s.substr(1), t.substr(1));                       // char matched            
    else if(s[0] != t[0])
    {   int r1 = 1 + minOperationsToMakeStringsSameBF(s.substr(1), t);                    // insertChar in t
    	int r2 = 1 + minOperationsToMakeStringsSameBF(s, t.substr(1));                    // removeChar from t
    	int r3 = 1 + minOperationsToMakeStringsSameBF(s.substr(1), t.substr(1));          // replaceChar of t
	    r = min(r1, min(r2,r3));   }
	    
		                                        
	return r;
}
                                                           
int minOperationsToMakeStringsSameM(string s, string t, int **arr)                        // Memorization { O(m*n) }
{
	int i=s.size(), j=t.size();    
	   
	if(i==0 || j==0)       
	return max(i, j);
	else if(arr[i][j] != -1)
	return arr[i][j];
 
 
	if(s[0] == t[0])
	arr[i][j] = minOperationsToMakeStringsSameM(s.substr(1), t.substr(1), arr);           // char matched            
    else if(s[0] != t[0])
    {   int r1 = 1 + minOperationsToMakeStringsSameM(s.substr(1), t, arr);                // insertChar in t
    	int r2 = 1 + minOperationsToMakeStringsSameM(s, t.substr(1), arr);                // removeChar from t
    	int r3 = 1 + minOperationsToMakeStringsSameM(s.substr(1), t.substr(1), arr);      // replaceChar of t
	    arr[i][j] = min(r1, min(r2,r3));   }

	                                            
	return arr[i][j];
}
                                         
                                                                                                   
int main()
{
	string s="abc", t="xyb";
	int m=s.size(), n=t.size();
	cout<<"Min no of operations applied to make input strings "<<s<<" & "<<t<<" same, is:"<<endl;
                                                      
													           	
    cout<<minOperationsToMakeStringsSameBF(s, t)<<endl;
    
                                         	
	int **arr1 = new int*[m+1];
	for(int i=0; i<m+1; i++)
	{   arr1[i] = new int[n+1]; 
	    for(int j=0; j<n+1; j++)
	    arr1[i][j] = -1;    }
    cout<<minOperationsToMakeStringsSameM(s, t, arr1)<<endl; 
                    
                    
    int **arr2 = new int*[m+1];                                                           // Dynamic Programming { O(m*n) }
	for(int i=0; i<m+1; i++)
	arr2[i] = new int[n+1]; 
	 
	arr2[0][0] = 0;
	for(int i=1; i<m+1; i++)
	arr2[i][0] = i; 
	for(int j=1; j<n+1; j++)
	arr2[0][j] = j; 
	for(int i=1; i<m+1; i++)
	{   for(int j=1; j<n+1; j++)
        {	
		    if(s[m-i]==t[n-j])
            arr2[i][j] = arr2[i-1][j-1];                                                  // char matched
     	    else
    	    {   int r1 = 1 + arr2[i-1][j];                                                // insertChar in t
            	int r2 = 1 + arr2[i][j-1];                                                // removeChar from t
            	int r3 = 1 + arr2[i-1][j-1];                                              // replaceChar of t
	            arr2[i][j] = min(r1, min(r2,r3));   }
  
		}
    }
    cout<<arr2[m][n]<<endl; 
}
 

 










