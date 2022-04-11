#include<stdio.h>
#include<limits.h>


int read(int *x, int n)    // taking input as Unsorted Array
{ 
   printf("Enter %d Array elements: ",n);

   int maxX=INT_MIN;
    
   for(int i=0; i<n; i++)
   {  scanf("%d",(x+i)); 
      maxX = (*(x+i) > maxX) ? *(x+i) : maxX;  }    
	  
   return maxX; 
}

int range = 10;
 
void countsort(int arr[],int n,int place)
{
        int i,freq[range]={0};         //range for integers is 10 as digits range from 0-9
        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}

void radixsort(int arr[],int n,int maxx)            //maxx is the maximum element in the array
{
        int mul=1;
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
}  
  	   
void print(int *x, int n)   // printing Sorted Array
{  
   printf("Array elements in ascending order: ");
   
   for(int i=0; i<n; i++)
   printf("%d  ",*(x+i));   
} 	   

int main()
{ 
   int arr[10];

   int maxX = read(arr,10);
   radixsort(arr,10,maxX);
   print(arr,10);
}


/*

10 21 17 34 44 11 654 123 54 1

*/








