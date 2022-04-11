#include <bits/stdc++.h>
using namespace std;


int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                                         // creating Adjacency matrix                    
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                           // storing input graph                             
	{  int v1, v2;
	   cin>>v1>>v2;
	   arr[v1][v2] = 1;
	   arr[v2][v1] = 1;	 }
	
	return arr;
} 

int noOfThreeVertexTrianglesInGraph(int **arr, int nV)
{
	int count = 0; 
	for(int i=0; i<nV; i++)
	{  for(int j=i+1; j<nV; j++)
	   	{  for(int k=j+1; k<nV; k++)
	       { 
		      if(arr[i][j]==1 && arr[j][k]==1 && arr[k][i]==1) 
	          count++;                                                // increase count when a 3 vertex cycle appears               
	       }
		}  
	} 
	
	return count;
}

int main()
{ 
	int nV, nE;
	cout<<"Enter no of vertices & edges: ";
	cin>>nV>>nE;                                              
	int **arr = storeInputGraph(nV, nE);
 

	
	cout<<"\nNo of 3 vertex triangles in the graph: ";
	cout<<noOfThreeVertexTrianglesInGraph(arr,nV)<<endl;
	
	for(int i=0; i<nV; i++)                                           // deleting the memory after use         
	delete [] arr[i];
	delete [] arr; 
}

 
/*

8 10

0 1
0 2
2 3
0 3
2 5
5 4
3 5
3 4
5 6
6 7
 
*/


/*  

                  0
                 /|\
                / | \
               1  2--3
                  | / \
                  |/   \
                  5-----4
                  | 
                  6
                  | 
                  7
 
*/












