#include <bits/stdc++.h>
using namespace std;

// static variable = (its lifetime is global but defination is local), (its value in previousFunctionCall remains same in nextFunctionCall) 
 
void fun()
{ 
    static int count = 0;               // static variable  
    cout << count << " ";
       
    count++;                            // value is updated and will be carried to nextFunctionCalls
}
  
  
int main()
{ 
    for(int i=0; i<5; i++)    
    fun(); 
}

 

















