#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}


int main()
{ 
    long startTime = getTimeinMicroSeconds();
   
    int n = 100000;
    for(int j=0; j<5; j++) 
	{  int arr[n];
       for(int i=0; i<n; i++)
       arr[i] = n-i;
       sort(arr, arr+n);  }
       
    long endTime = getTimeinMicroSeconds();
   
    cout<<"n="<<n<<"  time="<<endTime-startTime<<endl;
}







 






