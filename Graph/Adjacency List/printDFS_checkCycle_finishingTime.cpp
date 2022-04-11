#include <bits/stdc++.h>
using namespace std;  
  

class Graph                                     // Graph class represents a directed graph using adjacency list representation
{ 
    int V;                                      // no of vertices  
    list<int> *adj;                             // Pointer to an array containing adjacency lists  
    
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
 
		   public: 
    Graph(int V);                               // Constructor 
                                     
    void addEdge(int v, int w);                 // function to add an edge to graph 
     
    void DFS(int v, bool *visited);
    
    void finishingTimeDFS(int v, bool *visited, int *FT);
    
    bool isCyclic();                            // returns true if there is a cycle in this graph 
}; 

  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);                                              // Add w to v’s list. 
} 
     
    
void Graph::DFS(int v, bool *visited)
{
    visited[v] = true;                                               // Mark the current node as visited and print it
    cout << v << " ";
  

    list<int>::iterator i;                                           // Recur for all the vertices adjacent to this vertex
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

int x=1;

void Graph::finishingTimeDFS(int v, bool *visited, int *FT)
{
	FT[v] = x;
	x++; 
    visited[v] = true;                                               // Mark the current node as visited and print it 
  

    list<int>::iterator i;                                           // Recur for all the vertices adjacent to this vertex
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            finishingTimeDFS(*i, visited, FT);
}

 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)                                      // Mark the current node as visited and part of recursion stack
    { 
        visited[v] = true;
        recStack[v] = true;
  
        list<int>::iterator i;                                   // Recur for all the vertices adjacent to this vertex
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;                                         // remove the vertex from recursion stack
    return false;
}
 

bool Graph::isCyclic()                                           // Returns true if the graph contains a cycle, else false
{ 
    bool *visited = new bool[V];                                 // Mark all the vertices as not visited and not part of recursion stack
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 

    for(int i = 0; i < V; i++)                                    // Call the recursive helper function to detect cycle in different DFS trees
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
 
 // DFT = DFS 
                      
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
     
     
    bool visited[nV] = {0};                                     // Mark all the vertices as not visited 
	cout<<"\n\nGraph traversal in DFT order: ";                 // printing graph in DFS (Depth First Search) order   
	g.DFS(0, visited); 
	         
			         
	cout<<"\n\nIs given graph cyclic: ";	                        
    if(g.isCyclic())
    cout<<"Yes";
    else
    cout<<"No"; 


    bool visitedV[nV] = {0};                                    // Mark all the vertices as not visited 
    int FT[nV];
    cout<<"\n\n[Vertex]  [Finishing Time]"<<endl;  
	g.finishingTimeDFS(0, visitedV, FT); 
	for(int i=0; i<nV; i++)
	cout<<"    "<<i<<"\t\t"<<FT[i]<<endl;
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
1 6

             Input Graph

     0------>1----->3----->4----->5
      \     /\     /      /\      |
       \    |     /       |       |
         \  |   /         |       |  
         _\|| |/_         |       \/
		    2------------>6<------7
 
*/















