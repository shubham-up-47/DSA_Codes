#include <bits/stdc++.h>
using namespace std;


template <typename T, typename V>                       

class Pair
{
   T x;
   V y;
   
     public:
   void setX(T x)
   {  this->x = x;  }
   
   T getX()
   {  return x;  }	
	
   void setY(V y)
   {  this->y = y;  }
   
   V getY()
   {  return y;  }	
};


int main()
{
   Pair<int,double>  pDouble;                            // double template (int, double)
   pDouble.setX(10);
   pDouble.setY(34.21);  
   cout<< pDouble.getX() <<"  "<< pDouble.getY() <<endl;
   	 
   Pair< Pair<int,double>, string>  pTriple1;            // triple template using nesting (int, double, char)        
   pTriple1.setX(pDouble);                               // copy assignment operator used (fact)
   pTriple1.setY("nitt");  
   cout<< pTriple1.getX().getX() <<"  "<< pTriple1.getX().getY() <<"  "<< pTriple1.getY() <<endl; 
}






















