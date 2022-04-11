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

bool findCycleDFS(int currV, int parentV, int **arr, int nV, bool *visitedV, vector<int> &dfs)         // finding 1 cycle & print it 
{
	visitedV[currV] = true;
	dfs.push_back(currV);
	
	for(int i=0; i<nV; i++)
	{ 
	    if(arr[currV][i]>0 && visitedV[i] && parentV != i)
		{   dfs.push_back(i);
		    return true;   } 
		    
		if(arr[currV][i]>0 && !visitedV[i])
		{ 	bool r = findCycleDFS(i, currV, arr, nV, visitedV, dfs);
		     
			if(r==true)
			return true;   } 
	}
	
 	dfs.pop_back();
	return false; 
}
 
void isCyclePresent(int **arr, int nV)
{
	bool visitedV[nV] = {0};
	vector<int> dfs;
	 
	for(int i=0; i<nV; i++)
	{
	    if(!visitedV[i])
	    {   bool r = findCycleDFS(0, -1, arr, nV, visitedV, dfs);
	
  	        if(r==true)
	        {   cout<<"Yes"<<endl;
	            return;   }
        }
	} 
 
	cout<<"No"<<endl;
}

int x = 1; 
 
void subgraphTraversalDFS(int **arr, int nV, int currV, bool *printedV, int *FT)
{
	FT[currV] = x;
	x++;
	printedV[currV] = true;
	
	for(int i=0; i<nV; i++)
	{
	   if(i==currV)                                      // skip if vertex is already printed / no edge there   
	   continue;
	   else if(arr[currV][i]==1 && !printedV[i])
	   subgraphTraversalDFS(arr, nV, i, printedV, FT); 
	} 
}

void traversalDFS(int **arr, int nV)
{
	bool printedV[nV] = {0};                        // storing that vertex [i] is already printed or not   
	int FT[nV];
	                         
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])                             // using printedV[nV] helps in avoiding vertex repetition & printing discontinuous graph
	   subgraphTraversalDFS(arr, nV, i, printedV, FT); 
	} 
	
	for(int i=0; i<nV; i++)
	cout<<"    "<<i<<"\t\t"<<FT[i]<<endl;
	
	delete [] printedV;
}

 // DFS/DFT (downward traversal along edges & recursive code)   { O(n²) }                                            
 //  (V=Vertex), (E=Edge), (DFS=Depth First Search), (DFT=Depth First Traversal)                 

int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                  // storing input graph in Adjacency Matrix                    
	
	
	cout<<"\n\nGraph traversal in DFT order: ";             // printing graph in DFS (Depth First Search) order              
	printGraphDFS(arr, nV);
 
 
    cout<<"\n\nIs given graph cyclic: ";                   // printing graph in DFS (Depth First Search) order              
	isCyclePresent(arr, nV);

           
    cout<<"\n[Vertex]  [Finishing Time]"<<endl;             // printing graph in DFS (Depth First Search) order              
	traversalDFS(arr, nV);
 
 
	for(int i=0; i<nV; i++)                                 // deleting the memory after use 
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
 
 




 







