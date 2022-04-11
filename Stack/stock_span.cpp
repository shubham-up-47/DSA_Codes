#include <bits/stdc++.h>
using namespace std;


int* stockPriceToStockSpan(int stockPrice[], int n)
{
	stack<int> s;            // in (i)th loop, stack will store (i-1) & (indexes between (i-2) to (0) where price is higher than stockPrice[i]) 
	int *stockSpan = new int[n];
	
	for(int i=0; i<n; i++)
	{
	   while( !s.empty() && (stockPrice[s.top()] < stockPrice[i]) )	
	   s.pop();
	   
	   int j = (s.size()==0) ? (-1) : (s.top());                // stockPrice[s.top()] >= stockPrice[i]
	   
	   stockSpan[i] = i-j;   // stockSpan[i] = no of consecutive previous days (starting from day (i)) when (stockPrice < stockPrice[i])
	                                                                                 
	   s.push(i);	                                             
	} 
	                                                                   
	return stockSpan;
}


int main()
{
   int stockPrice[9] = {5,3,8,7,10,7,7,12,16};                  // array storing stock price
   
   int *stockSpan = stockPriceToStockSpan(stockPrice, 9);       // array storing stock span
   
   cout<<"\nPrice: ";
   for(int i=0; i<9; i++)
   cout<<stockPrice[i]<<"  ";
   cout<<"\nSpan:  ";
   for(int i=0; i<9; i++)
   {   cout<<stockSpan[i]<<"  ";
       if(stockPrice[i]/10 != 0)
       cout<<" ";   }
   
   delete [] stockSpan; 
}









 

 
