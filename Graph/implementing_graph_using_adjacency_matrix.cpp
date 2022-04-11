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

void printConnectedSubgraphDFS(int **arr, int nV, int startV, bool *printedV)
{
	cout<<startV<<" ";
	printedV[startV] = true;
	
	for(int i=0; i<nV; i++)
	{
	   if(i==startV)                                      // skip if vertex is already printed / no edge there   
	   continue;
	   else if(arr[startV][i]==1 && !printedV[i])
	   printConnectedSubgraphDFS(arr, nV, i, printedV); 
	} 
}

void printGraphDFS(int **arr, int nV)
{
	bool *printedV = new bool[nV];                        // storing that vertex [i] is already printed or not  
	for(int i=0; i<nV; i++)
	printedV[i] = false;                                  // using printedV[nV] helps in avoiding vertex repetition & printing discontinuous graph
	
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])
	   printConnectedSubgraphDFS(arr, nV, i, printedV); 
	} 
	
	delete [] printedV;
}

void printConnectedSubgraphBFS(int **arr, int nV, int startV, bool *printedV)
{
	queue<int> vList;                                     // storing vertices levelwise to print graph level wise        
	vList.push(startV);
	printedV[startV] = true;
	
	while(vList.size() != 0)
	{
	   int currV = vList.front();
	   vList.pop();
	   cout<<currV<<" ";
		
	   for(int i=0; i<nV; i++)
	   {   if(i==currV)                                   // skip if vertex is already printed / no edge there  
	       continue;
	       else if(arr[currV][i]==1 && !printedV[i])
	       {  vList.push(i);
			  printedV[i] = true;  }   }  
	} 
}

void printGraphBFS(int **arr, int nV)
{
	bool *printedV = new bool[nV];                        // storing that vertex [i] is already printed or not     
	for(int i=0; i<nV; i++)
	printedV[i] = false;                                  // using printedV[nV] helps in avoiding vertex repetition & printing discontinuous graph
	
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])
	   printConnectedSubgraphBFS(arr, nV, i, printedV); 
	} 
	
	delete [] printedV;
}

 // DFS (downward traversal along edges & recursive code)   { O(n²) }                                            
 // BFS (level wise traversal using queue & iterative code)   { O(n²) }                     

int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                  // storing input graph in Adjacency Matrix                    
	
	cout<<"\nGraph traversal in DFS order: ";             // printing graph in DFS (Depth First Search) order              
	printGraphDFS(arr, nV);
	
	cout<<"\nGraph traversal in BFS order: ";             // printing graph in BFS (Breadth First Search) order   
	printGraphBFS(arr, nV);
	
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
   -> Tree (minimally connected graph)      
*connected graph
*having no cycle
*no of edges = n-1
  
  
 (V=Vertex), (E=Edge), (DFS=Depth First Search), (BFS=Breadth First Search) 
 
*/





 


