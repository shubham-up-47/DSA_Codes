#include<stdio.h>
#define MAX 20

void readsparse(int b[MAX][3])
{
   int i,t,m,n;
   printf("Enter no. of rows and columns:");
   scanf("%d%d",&m,&n);
   printf("No. of non-zero triples:");
   scanf("%d",&t);
   b[0][0]=m;
   b[0][1]=n;
   b[0][2]=t;
   
   printf("Enter the triples(row,column,value):\n");
   for(i=1;i<=t;i++)
   {
      scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
   }
}


void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;
	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	k=1; 
	n=b1[0][2];
	
    for(i=0; i<b1[0][1]; i++)
    { for(j=1; j<=n+1; j++)
      {
	    if(i==b1[j][1])
		{  b2[k][0]=i;
           b2[k][1]=b1[j][0];
           b2[k][2]=b1[j][2];
           k++;   }
      }
    }
}


void printsparse(int b[MAX][3])
{
   int i,t;
   t=b[0][2];
   printf("\nrow\tcolumn\tvalue");
   
   for(i=1;i<=t;i++)
   {   printf("\n%d\t%d\t%d",b[i][0],b[i][1],b[i][2]);   }
}

int main()
{
    int b1[MAX][3],b2[MAX][3],m,n; 
    
    readsparse(b1);
    transpose(b1,b2);
    printsparse(b2);
}
 
 
 
 
 
 
 

