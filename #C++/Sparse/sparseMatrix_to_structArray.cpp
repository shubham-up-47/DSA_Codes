#include<stdio.h>
using namespace std;

struct sparseStructArray
{   int i,j;
	int value;  };
	
int main()
{
    int m,n,count=0;	
    scanf("%d%d",&m,&n);
	
   	int arr[m][n];                                   // sparse (matrix representation) 
	for(int i=0;i<m;i++)
	{ 	for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0)
			count++;
		}
	}
	
	sparseStructArray x[count+1];                          // sparse (struct array representation) 
	x[0].i=m;
	x[0].j=n;
	x[0].value=count;
	for(int i=0,k=1;i<m;i++)
	{ 	for(int j=0;j<n;j++)
		{
			if(arr[i][j]!=0)
			{
				x[k].i=i;
				x[k].j=j;
				x[k].value=arr[i][j];
				k++; 	}
		}
	}
	
	for(int i=0;i<=count;i++)
	{  printf("%d %d %d\n",x[i].i,x[i].j,x[i].value);  }
	
	return 0;
}




/*
15 0 0 22 0 -15
0 11 3 0 0 0
0 0 0 -6 0 0
0 0 0 0 0 0
91 0 0 0 0 0
0 0 28 0 0 0
*/


