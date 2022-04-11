#include <bits/stdc++.h>
using namespace std;  
  
 
class Graph                                     // Graph class represents a directed graph using adjacency list representation
{ 
    int V;                                      // no of vertices  
    list<int> *adj;                             // (2D list) Pointer to an array containing adjacency lists  
    void goToAllPathsUtil(int v1, int v2, bool visited[], int path[], int index);      // a recursive function used by goToAllPaths()
          
		   public: 
    Graph(int V);                              // Constructor 
    
    bool pathExist;                             // variable to indicate if path exist or not
                                               
    void addEdge(int v, int w);                 // function to add an edge to graph 
    
    void goToAllPaths(int v1, int v2);
    
    void printDegree(int v, int nV);
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);                                             // Add w to v’s list. 
} 
 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and index is current 
// index in path[] 

void Graph::goToAllPathsUtil(int v1, int v2, bool visited[], int path[], int index)  // recursive function to go to all paths from 'v1' to 'v2'
{ 
    // Mark the current node as visited and store it in path[] 
    visited[v1] = true;
    path[index]=v1;
    index++;
                              
    if(v1==v2)
	{                                              // If current vertex is same as v2, then path exist  
        pathExist=true; 
    }
    else
	{                                              // If current vertex is not v2, Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i) 
            if (!visited[*i]) 
                goToAllPathsUtil(*i, v2, visited, path, index); 
    }
                                          
    index--;
    visited[v1] = false;                           // Remove current vertex from path[] and mark it as unvisited 
} 
  
void Graph::goToAllPaths(int v1, int v2)           // DFS traversal of the vertices reachable from v, It uses recursive goToAllPathsUtil 
{ 
    bool *visited = new bool[V];                   // Mark all the vertices as not visited 
    for(int i = 0; i < V; i++) 
    visited[i] = false;
        
    int *path = new int[V];                        // Create an array to store paths 
     
    int index = 0;                                 // Initialize path[] as empty 
    
    pathExist=false;
     
    goToAllPathsUtil(v1,v2,visited,path,index);     // Call the recursive helper function to go to all paths 
} 

void Graph::printDegree(int v, int nV)              // recursive function to go to all paths from 'v1' to 'v2'
{ 
    int inC=0, outC=0;                                       
        
	list<int>::iterator it; 
    for(it=adj[v].begin(); it != adj[v].end(); ++it) 
    outC++;
    
    for(int i=0; i<nV; i++)
    {  
	   list<int>::iterator t; 
       for(t=adj[i].begin(); t!=adj[i].end(); ++t) 
       {  if(*t==v)
       	  inC++;   }
	}
               
    if(inC==outC)                           
    cout<<"Degree of vertex "<<v<<" is: "<<inC<<endl;
    else
	cout<<"\nIndegree="<<inC<<" and "<<"Outdegree="<<outC<<" for vertex "<<v<<endl; 
} 
  
 
int main() 
{
    int nV=0, nE;
    cin>>nE;
    
    Graph g(nE);
    
    for(int i=0; i<nE; i++)
    {  int v1, v2;
	   cin>>v1>>v2;	
	   g.addEdge(v1,v2); 
	   
	   nV = max(nV, v1);
	   nV = max(nV, v2);  }
	nV++;
   
	cout<<"Enter v to find degree: ";
	int v;
	cin>>v;
	
	cout<<"Enter v1 & v2 to check path: ";
	int v1, v2;
	cin>>v1>>v2;
	
	g.goToAllPaths(v1,v2);
	
	cout<<"\n\nIs input graph a complete graph: ";
	if((nE*(nE-1))/2 == nV)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	
	 
	g.printDegree(v, nV);

	cout<<"\nDoes path exist between "<<v1<<" and "<<v2<<": ";
	if(g.pathExist)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
} 


/*

11
0 1
1 3
2 1
3 2
3 4
4 5
6 4
5 7
7 6
0 2
2 6 
3
1 6

             Input Graph

     0------>1----->3----->4----->5
      \     /\     /      /\      |
       \    |     /       |       |
         \  |   /         |       |  
         _\|| |/_         |       \/
		    2------------>6<------7
 
*/








