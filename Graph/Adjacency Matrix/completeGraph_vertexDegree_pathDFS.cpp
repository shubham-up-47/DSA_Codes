#include <bits/stdc++.h>
using namespace std;

// Graph = (set of Vertices & Edges), (no of edges in connected graph "n-1 <= no of edges <= nC2")         

int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                             // creating adjacency matrix                                  
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                               // taking input                     
	{  int v1, v2;
	   cin>>v1>>v2;
	   arr[v1][v2] = 1;
	   arr[v2][v1] = 1;	 }
	
	return arr;
}

void checkCompleteGraph(int **arr, int nV, int nE)
{
	cout<<"\n\nIs given input graph a Complete graph: ";
	
	for(int i=0; i<nV; i++)
	{  
	   if(arr[i][i] > 0)
	   {  cout<<"No"<<endl;
	      return;  }	
	}
	
	if((nV*(nV-1))/2 == nE)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}

void findDegreeOfVertex(int **arr, int nV, int currV)
{                     
    int inC=0, outC=0; 
	
	for(int i=0; i<nV; i++)
	{  
	   if(arr[i][currV] > 0)
	   inC++;
	   
	   if(arr[currV][i] > 0)
	   outC++;	
	}
	
	if(inC == outC)
	cout<<"\nDegree of vertex "<<currV<<" is: "<<inC<<endl;
	else
	cout<<"\nIndegree="<<inC<<" and "<<"Outdegree="<<outC<<" of vertex "<<currV<<endl; 
}
 
bool DFStraversal(int **arr, int nV, int v1, int v2, bool *visitedV)
{
	if(arr[v1][v2]==1)                            // checking v1 & v2 are adjacent or not
	return 1;
	 
	for(int i=0; i<nV; i++)                       // checking nearest/nextNearest/nextToNextNearest... of v1 & v2 are adjacent or not     
	{
	   if(arr[v1][i]==1 && !visitedV[i])
	   {  visitedV[i] = 1;
	      if(DFStraversal(arr, nV, i, v2, visitedV))
	      return 1;  }
	} 
	
	return 0;                                     // if v1 & v2 are inSeperateSubgraphs then noPathExistFromV1toV2 so return false 
}
         
void hasPathV1toV2(int **arr, int nV, int v1, int v2)
{ 
	bool visitedV[nV];
	for(int i=0; i<nV; i++)
	visitedV[i] = 0;
	
	cout<<"\nIs V1 to V2 has path: ";             // checking that path from v1 to v2 is present or not           

	cout<<(DFStraversal(arr,nV,v1,v2,visitedV) ? "Yes" : "No")<<endl;
	
}
 
int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                  // storing input graph in Adjacency Matrix                    

	int currV;
	cout<<"Enter vertex to find its degree: ";                          
	cin>>currV;
	
	int v1, v2;
	cout<<"Enter 2 vertices to check that path exist between them or not: ";                        
	cin>>v1>>v2;
	
	
	checkCompleteGraph(arr, nV, nE);
	
	findDegreeOfVertex(arr, nV, currV);
	
	hasPathV1toV2(arr, nV, v1, v2);
	
	
	for(int i=0; i<nV; i++)                               // deleting the memory after use 
	delete [] arr[i];
	delete [] arr; 
}

 
/*

8 7
0 1
1 3
1 6
3 7
2 4
2 5
4 5
1
5 7

 
      Input graph  

                  0
      2           |
     /\           1
    /  \          /\
   4----5        /  \
                6    3
                     |
                     7
*/
 
 
/*  
  
 (V=Vertex), (E=Edge), (DFS=Depth First Search), (BFS=Breadth First Search) 
 
*/





 








