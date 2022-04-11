#include <bits/stdc++.h>
using namespace std;
                                                                                                                                               
 // Path = traversal in which no edge & no vertex repeat                                
                                                                                                       
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                     // creating adjacency matrix      
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                       // storing graph         
	{  int v1, v2;  
	   cin>>v1>>v2;
	   arr[v1][v2] = 1;
	   arr[v2][v1] = 1;	 }
	
	return arr;
}

bool hasPathV1toV2(int **arr, int nV, int v1, int v2, bool *visitedV)
{
	if(arr[v1][v2]==1)                            // checking v1 & v2 are adjacent or not
	return 1;
	 
	for(int i=0; i<nV; i++)                       // checking nearest/nextNearest/nextToNextNearest... of v1 & v2 are adjacent or not     
	{
	   if(arr[v1][i]==1 && !visitedV[i])
	   {  visitedV[i] = 1;
	      if(hasPathV1toV2(arr, nV, i, v2, visitedV))
	      return 1;  }
	} 
	
	return 0;                                     // if v1 & v2 are inSeperateSubgraphs then noPathExistFromV1toV2 so return false 
}
                                      
vector<int>* V1toV2Path_usingDFS(int **arr, int nV, int currV, int endV, bool *visitedV)
{
	visitedV[currV] = true;
	
	if(currV==endV)                               // if currV is endV or not 
	{  vector<int> *r = new vector<int>();
	   r->push_back(currV);
	   return r;  }
	
	for(int i=0; i<nV; i++)                       // checking nearest/nextNearest/nextToNextNearest... of startV is endV or not 
	{  
		if(arr[currV][i]==0 || visitedV[i])
	    continue;
	   
	    vector<int> *r = V1toV2Path_usingDFS(arr, nV, i, endV, visitedV); 
	    if(r != NULL)
	    {  r->push_back(currV);
	       return r;  }
	} 
	
	return NULL;                                  // if v1 & v2 are inSeperateSubgraphs then noPathExistFromV1toV2 so return NULL 
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
			  visitedV[i] = true;   
			
		      if(i==endV)
	          break;  }   }
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
	for(int i=0; vp!=NULL && i<vp->size(); i++)
	cout<<vp->at(i)<<" ";
	cout<<endl;
}

int countV1toV2Paths(int **arr, int nV, int currV, int endV, vector<bool> visitedV)
{                                                 // we are copyingVectorData in eachFunctionCalls bcz diff visitedVertexData for diff paths 
	if(currV==endV)
	return 1;  
	
	int c = 0;
	visitedV[currV] = 1;
	for(int i=0; i<nV; i++)                                 
	{
		if(arr[currV][i]==1 && !visitedV[i])      // counting all unvisited paths (considering currV=sourceVertex) 
	    c  += countV1toV2Paths(arr, nV, i, endV, visitedV);  
	} 
	
	return c;                                                                                    
}
 

int main()
{ 
	int nV, nE;
	cout<<"Enter no of vertices & edges: ";
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);          // storing graph in Adjacency Matrix    
	bool *visitedV = new bool[nV];                // storing that vertex [i] is already visited or not 
	vector<int> *vp;                              // storing address of vector having v1 to v2 path                                   
	int v1,v2;
	cout<<"Enter vertex 1 & vertex 2: ";
	cin>>v1>>v2;
	
	
	cout<<"\nIs V1 to V2 has path: ";             // checking that path from v1 to v2 is present or not           
	for(int i=0; i<nV; i++)
	visitedV[i] = 0;
	cout<<(hasPathV1toV2(arr,nV,v1,v2,visitedV) ? "true" : "false")<<endl;
	
	
	cout<<"\nV1 to V2 DFS path: ";                // printing v1 to v2 path using DFS
	for(int i=0; i<nV; i++)
	visitedV[i] = 0;
	vp = V1toV2Path_usingDFS(arr,nV,v1,v2,visitedV);
	printPath(vp);
		
	
	cout<<"\nV1 to V2 BFS path: ";	              // printing v1 to v2 path using BFS (this path is shortest path between v1 & v2) 
	for(int i=0; i<nV; i++)
	visitedV[i] = 0;                                                             
	vp = V1toV2Path_usingBFS(arr,nV,v1,v2,visitedV);     
	printPath(vp);
	
	
	cout<<"\nNo of paths from V1 to V2: ";        // printing no of paths from v1 to v2    
    vector<bool> visited(nV, false);              // best way to make initialized array (always use vector)                       
	int count = countV1toV2Paths(arr,nV,v1,v2,visited);
	cout << count << endl;
	
	for(int i=0; i<nV; i++)                       // deleting the memory after use
	delete [] arr[i];
	delete [] arr;                                
}

 
/*

8 9

0 1
0 2
0 3
2 5
3 5
3 4
4 5
5 6
6 7

0 4


             Input Graph

                  0
                 /|\
                / | \
               1  2  3
                  | / \
                  |/   \
                  5-----4
                  | 
                  6
                  | 
                  7
 
*/












