#include<stdio.h>


void find_N_X_3_sparse(int ar[50][50],int r,int c,int sparse[50][3])
{
    int i,j,k=0;
    
    sparse[0][0]=r;
    sparse[0][1]=c;
 
    for(i=0;i<r;i++)
	{	for(j=0;j<c;j++)
    	{	if(ar[i][j]!=0)
	    	{
	     	    k++;
		        sparse[k][0]=i;
	        	sparse[k][1]=j;
	            sparse[k][2]=ar[i][j];
	        }
    	}
    }
    
    sparse[0][2]=k;
 
    printf("\n\nInput sparse matrix in nX3 form\n");
    for(i=0; i<=sparse[0][2]; i++)
	printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);  
}

void find_sparse_transpose(int sparse[50][3])                  // transpose for a[i][j] = a[i][n-j]      
{
	int tp1[50][3], tp[50][3], m=sparse[0][2], i, r, k=0;       // (k=element no of sorted) 
	
	
	tp1[0][0]=sparse[0][0];                                // tp1 = unsorted transpose sparse (bcz col no are in descending order when same row no)    
	tp1[0][1]=sparse[0][1];  
	tp1[0][2]=sparse[0][2];
	 
	for(i=1;i<=m;i++)                                     // making transpose
	{
	    tp1[i][0]=sparse[i][0];                           // row
	    tp1[i][1]=(sparse[0][1]-1) - sparse[i][1];        // column
	    tp1[i][2]=sparse[i][2];	                          // value
	}
              
	
	tp[0][0]=sparse[0][0];                                // tp = sorted transpose sparse(bcz rows are in ascending order)  
	tp[0][1]=sparse[0][1];
	tp[0][2]=sparse[0][2];
	       	
	for(r=0; r<sparse[0][0]; r++)                         // sorting (r=row no, k=element no of sorted, i=element no of unsorted)      
 	{   for(i=m; i>=1; i--)                               // traversing bottom to up (changing descending order to ascending order)                 
	    {   if(tp1[i][0]==r)
		    {
		    	k++;
		    	tp[k][0]=tp1[i][0];
		    	tp[k][1]=tp1[i][1];
		    	tp[k][2]=tp1[i][2];
		    }
	    }
    }
    
    printf("\nTranspose sparse matrix in nX3 form\n");
    for(i=0;i<=tp[0][2];i++)
	printf("%d\t%d\t%d\n",tp[i][0],tp[i][1],tp[i][2]);  
}

int main()
{
	int arr[50][50],r,c,i,j;
	int sparse[50][3]; 
	scanf("%d",&r);                                   // row
	scanf("%d",&c);                                   // column
 
	for(i=0; i<r; i++)
	{	for(j=0; j<c; j++)
	    scanf("%d",&arr[i][j]);    }
	  
	find_N_X_3_sparse(arr,r,c,sparse);
	
	find_sparse_transpose(sparse);
}


/*

6 6 
15 0 0 22 0 -15
0 11 3 0 0 0
0 0 0 -6 0 0
0 0 0 0 0 0
91 0 0 0 0 0
0 0 28 0 0 0

*/





