#include <bits/stdc++.h>
using namespace std;


class triangle
{    public:
    int a;
	int b;
	int c;  
};
 
float area(int x, int y, int z)
{  
    float A, s=(x+y+z)/2.0;
    
    A = s*(s-x)*(s-y)*(s-z);
    return A;   
}
 
void sort_by_area(triangle *t, int n)                      // selection sort
{     
    for(int i=0; i<n-1; i++)
    {  int m=i;
        
       for(int j=i+1; j<n; j++)
       {  if(area(t[j].a,t[j].b,t[j].c) < area(t[m].a,t[m].b,t[m].c))
	      m = j;  }
         
       int t1 = t[m].a, t2 = t[m].b, t3 = t[m].c;
       
       t[m].a = t[i].a;   
	   t[m].b = t[i].b;    
	   t[m].c = t[i].c;
	   
       t[i].a = t1;        
	   t[i].b = t2;         
	   t[i].c = t3;
    }
}


int main()
{   
    int n;
	cin>>n;
	
	triangle *t = new triangle[n];
	
	for(int i=0; i<n; i++) 
	cin >> t[i].a >> t[i].b >> t[i].c;
	
	sort_by_area(t, n);
	
	for(int i=0; i<n; i++) 
	cout<<endl<< t[i].a <<" "<< t[i].b <<" "<< t[i].c; 
}

 
/*

3
5 4 3
12 5 13
7 7 7

*/











