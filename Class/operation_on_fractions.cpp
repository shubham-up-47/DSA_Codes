#include <bits/stdc++.h>
using namespace std;


class Fraction                                       // simply the fraction after doing any operation
{     private:
    int n,d;                                         // n = numerator, d = denominator	
	
      public:
    Fraction (int num, int den)                      // parametrized constructor
    {  n = num;  
       d = den;  }	
         
    void print() const                               // printing (const function - doesn't change any property of object)   
    {  cout<<n<<" / "<<d<<endl;  }
       
    void simplify()                                  // simplifying the fraction 
	{  int gcd = 1;
	   int j = min(n,d);
	   
	   for(int i=1; i<=j; i++)
	   {  if(n%i==0 && d%i==0)
	      gcd = i;  }
	         
	   n = n/gcd;
	   d = d/gcd;   }   
	                                               
	Fraction operator+(Fraction const &f) const      // addition (const & argument- to keep value constant & low space complexity)
	{  int i = (f.d)*n + d*(f.n);                    // (f.n, f.d) = (numerator, denominator) of fraction present after '+' sign
	   int lcm = d*(f.d); 
	   
	   Fraction fNew(i,lcm);
	   fNew.simplify();
	   
	   return fNew;   }
	                                                                                            
	Fraction operator*(Fraction const &f) const      // multiplication
	{  int num = n*(f.n);
	   int den = d*(f.d);
                                           		
	   Fraction fNew(num,den);
	   fNew.simplify();
	   
	   return fNew;   } 
	
	bool operator==(Fraction const &f) const         // equality
	{  return (n==f.n && d==f.d);  }
	
	Fraction& operator++()                           // pre increment (& return - returning by reference, so it work properly if multiple ++ done)  
	{  n = n+d;
	   simplify();
	   
	   return *this;  }
	   
	Fraction operator++(int)                         // post increment (mug this syntax for post increment)
	{  Fraction fNew(n,d);
	
	   n = n+d;
	   simplify();
    
	   return fNew;  }
	   
	Fraction& operator+=(Fraction const &f)          // adding & updating value                                   
	{  int lcm = d*(f.d);
	   int i = (f.d)*n + d*(f.n);
	   
	   n = i;
	   d = lcm;
	   simplify();
	   
	   return *this;  } 
};

 
int main()
{
    Fraction f1(10,3);
	Fraction f2(5,2);
	
	Fraction f3 = f1+f2;                             // addition 
	f3.print();  
      
    Fraction f4 = f1*f2;                             // multiplication
    f4.print();
    
    if(f1==f2)                                       // equality
    cout<<"Equal"<<endl;
    else
    cout<<"Not equal"<<endl;
    
    ++f1;                                            // pre increment
    f1.print();
    
    Fraction f5 = ++f1;                              // pre increment
    f1.print();
    f5.print();
    
    Fraction f6 = ++(++f1);                          // pre increment
    f1.print();
    f6.print();
    
    Fraction f7 = f1++;                              // post increment
    f1.print();
    f7.print();
    
    int i=5, j=3; 
    (i += j) += j;                                   // adding & updating value
    cout<<i<<" "<<j<<endl;
    
    (f1 += f2) += f2;                                // adding & updating value
    f1.print();
    f2.print(); 
}








 


 
 
 
 
