#include <bits/stdc++.h>
using namespace std;


int main() 
{   
    int n,x,i,j;
    cin>>n;
    
	x = n+1;
  
    for(i=1; i<n; i++)
    { 
      for(j=1; j<n; j++)
      { if(i>=j)         x--;  
        cout<<x<<" ";  }    
	  
	  { if(i>=j)         x--;  
        cout<<x<<" ";  }  
    
	  for(j=n-1; j>=1; j--)
      { cout<<x<<" "; 
	    if(i>=j)    x++;  } 
	    
	  cout<<endl; 
    }
  
  
  
  
  
    {
	  for(j=1; j<n; j++)
      { if(i>=j)         x--;  
        cout<<x<<" ";  }    
	  
	  { if(i>=j)         x--;  
        cout<<x<<" ";  }  
    
	  for(j=n-1; j>=1; j--)
      { if(i>=j)         x++;  
        cout<<x<<" ";  } 
        
      cout<<endl;    
    }
    
    
    
   x=n+1; 
   
   for(i=n-1; i>=1; i--)
    {
      for(j=1; j<n; j++)
      { if(i>=j)         x--;  
        cout<<x<<" ";  }    
	  
	  { if(i>=j)         x--;  
        cout<<x<<" ";  }  
    
	  for(j=n-1; j>=1; j--)
      { cout<<x<<" "; 
	    if(i>=j)         x++;   } 
        
      cout<<endl;    
    } 
}












