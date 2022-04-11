#include <bits/stdc++.h>                            //  header file for stringstream is [ #include <sstream> ]       
using namespace std;                                            

 
int main() 
{
    int a=12, b=7;                           
    string p="abc", q="rs tu";
    
     
    stringstream ss; 
    ss << a << ',' << p << ',' << q << ',' << b;
    cout << ss.str() << endl;
    
    
    string s = ss.str(); 
    cout << s << endl;
}
















