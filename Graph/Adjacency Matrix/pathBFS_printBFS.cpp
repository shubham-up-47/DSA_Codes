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

vector<int>* V1toV2Path_usingBFS(int **arr, int nV, int startV, int endV, bool *visitedV)
{
	queue<int> vList;                             // queue for levelOrderTraversal           
	unordered_map<int,int> m;                     // map for storing (vertex, parentVertex) as (key, value) to get pathFromV2toV1
	
	vList.push(startV);
	visitedV[startV] = true; 
	while(vList.size()!=0 && vList.front()!=endV)
	{
	   int currV = vList.front();
	   vList.pop(); 
		
	   for(int i=0; i<nV; i++)
	   {   if(arr[currV][i]==1 && !visitedV[i])
	       {  vList.push(i);
	          m[i] = currV;
			  visitedV[i] = true;  }
			
		   if(i==endV)
	       break;   }  
	} 
	
	if(vList.size()==0)
	return NULL;
	else
	{  vector<int> *r = new vector<int>();
	   r->push_back(endV);
	   for(int i=endV; i!=startV; i=m[i])
	   r->push_back(m[i]);  
	   return r;  }                               // pathStored is shortestPathFromV1toV2 bcz levelWiseDistance comes (considering startV=rootVertex)
}

void printPath(vector<int> *vp)
{ 
    if(vp==NULL)
    return; 
    
	for(int i=vp->size()-1; i>=0; i--)
	cout<<vp->at(i)<<" ";
	cout<<endl;
}

 // BFS/BFT (level wise traversal using queue & iterative code)   { O(n²) }     
 // (V=Vertex), (E=Edge), (BFS=Breadth First Search), (BFT=Breadth First Traversal) 

int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                  // storing input graph in Adjacency Matrix                    
	 
	int v1, v2;
	cout<<"Enter V1 (source vertex) & V2 (end vertex): ";                        
	cin>>v1>>v2;
	 
	bool visitedV[nV] = {0};                             // storing that vertex [i] is already visited or not  
    vector<int> *vp;                                     // storing address of vector having v1 to v2 path     
	vp = V1toV2Path_usingBFS(arr,nV,v1,v2,visitedV);     
	 
	 
	cout<<"\n\nGraph traversal in BFT order: ";          // printing graph in BFS (Breadth First Search) order   
	printGraphBFS(arr, nV);
	                
 
	cout<<"\n\nV1 to V2 BFT path (shortest path): ";	 // printing v1 to v2 path using BFS (this path is shortest path between v1 & v2)  
	printPath(vp);
	
	                 
	for(int i=0; i<nV; i++)                              // deleting the memory after use 
	delete [] arr[i];
	delete [] arr; 
}

 
/*

8 9
0 1
1 6
1 3
6 7
2 4
2 5
4 5
3 6
3 7
0 6
 
      Input graph  

                  0
      2           |
     /\           1
    /  \          /\
   4----5        /  \
                3----6
                 \   |
                  \  | 
				    7
                  
*/
 
  


 





