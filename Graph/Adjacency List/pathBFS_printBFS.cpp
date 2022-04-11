#include <bits/stdc++.h>
using namespace std;  
  

class Graph                                     // Graph class represents a directed graph using adjacency list representation
{ 
    int V;                                      // no of vertices  
    list<int> *adj;                             // Pointer to an array containing adjacency lists  
 
		   public: 
    Graph(int V);                               // Constructor 
                                     
    void addEdge(int v, int w);                 // function to add an edge to graph 
     
    void BFS(int s);
    
	void printPathBFS(int s, int d);
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

  
void Graph::BFS(int s)                                               // s = source vertex to start BFS
{
   
    bool *visited = new bool[V];                                     // Mark all the vertices as not visited
    for(int i = 0; i < V; i++)
    visited[i] = false;
 
 
    list<int> queue;                                                 // Create a queue for BFS
 
   
    visited[s] = true;                                               // Mark the current node as visited and enqueue it
    queue.push_back(s);
 
   
    list<int>::iterator i;                                           // 'i' will be used to get all adjacent vertices of a vertex
 
    while(!queue.empty())
    {
        
        s = queue.front();                                           // Dequeue a vertex from queue and print it
        cout << s << " ";
        queue.pop_front();
 
        for (i = adj[s].begin(); i != adj[s].end(); ++i)             // for all adjacent unvisited vertices of s, mark them visited and enqueue it
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    
    cout<<endl;
}

 
void Graph::printPathBFS(int s, int d)
{
   
    bool *visited = new bool[V];                                       // Mark all the vertices as not visited
    for(int i = 0; i < V; i++)
    visited[i] = false;
 
 
    list<int> queue;                                                    // Create a queue for BFS
	unordered_map<int,int> m;                                       // map for storing (vertex, parentVertex) as (key, value) to get pathFromV2toV1
	
    visited[s] = true;                                              // Mark the current node as visited and enqueue it
    queue.push_back(s);
 
   
    list<int>::iterator i;                                          // 'i' will be used to get all adjacent vertices of a vertex
 
    while(!queue.empty() && queue.front()!=d)
    {
        
        int currV = queue.front();    
        queue.pop_front();
 
        for (i=adj[currV].begin(); i!=adj[currV].end(); ++i)         // for all adjacent unvisited vertices of s, mark them visited and enqueue it
        {
            if (!visited[*i])
            {   m[*i] = currV;
                visited[*i] = true;
                queue.push_back(*i);  }
            
            if(*i==d)
            break;
        }
    }

	if(queue.size()==0)
	return;
	else
	{  vector<int> *r = new vector<int>();
	   r->push_back(d);
	   for(int i=d; i!=s; i=m[i])
	   r->push_back(m[i]);  
	   
	   for(int i=r->size()-1; i>=0; i--)
	   cout<<r->at(i)<<" ";  }                     // pathStored is shortestPathFromV1toV2 bcz levelWiseDistance comes (considering startV=rootVertex)

    cout<<endl;
}
 
 // BFT = BFS 
                      
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
    
	cout<<"Enter v1 & v2 to find BFT path: ";
	int v1, v2;
	cin>>v1>>v2;
	 
	 
	cout<<"\n\nGraph traversal in BFT order: ";          // printing graph in BFS (Breadth First Search) order   
	g.BFS(0); 
	         
			         
	cout<<"\n\nV1 to V2 BFT path (shortest path): ";	 // printing v1 to v2 path using BFS (this path is shortest path between v1 & v2)  
	g.printPathBFS(v1, v2);  
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










