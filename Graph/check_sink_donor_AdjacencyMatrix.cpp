#include <bits/stdc++.h>
using namespace std;

// Graph = (set of Vertices & Edges), (no of edges in connected graph "n-1 <= no of edges <= nC2")         

int** storeInputGraph(int nV, int nE)
{
	int **graph = new int*[nV];                             // creating adjacency matrix                                  
	for(int i=0; i<nV; i++)
	{  graph[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   graph[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                 // taking input                     
	{  int v1, v2;
	   cin>>v1>>v2;
	   graph[v1][v2] = 1;	 }
	
	return graph;
}
 
void checkSink(int **graph, int nV, int currV)
{                     
    int in=0, out=0; 
	
	for(int i=0; i<nV; i++)
	{  
	   if(graph[i][currV] > 0)
	   in++;
	   
	   if(graph[currV][i] > 0)
	   out++;	
	}
	
	if(in==nV-1 && out==0)
	cout<<"\nVertex "<<currV<<" is a Sink"<<endl;
	else
	cout<<"\nVertex "<<currV<<" is not a Sink"<<endl; 
}


void checkDonor(int **graph, int nV, int currV)
{                     
    int in=0, out=0; 
	
	for(int i=0; i<nV; i++)
	{  
	   if(graph[i][currV] > 0)
	   in++;
	   
	   if(graph[currV][i] > 0)
	   out++;	
	}
	
	if(in==0 && out==nV-1)
	cout<<"\nVertex "<<currV<<" is a Donor"<<endl;
	else
	cout<<"\nVertex "<<currV<<" is not a Donor"<<endl; 
}
  
int main()
{ 
	int nV, nE, sV, dV;
	cin>>nV>>nE;
	int **graph = storeInputGraph(nV, nE);                  // storing input graph in Adjacency Matrix                    
 
	cout<<"Enter Vertex to check it is sink or not: ";                          
	cin>>sV;
	 
	cout<<"Enter Vertex to check it is donor or not: ";                        
	cin>>dV;
	 
	checkSink(graph, nV, sV);
	
	checkDonor(graph, nV, dV);
	 
	for(int i=0; i<nV; i++)                               // deleting the dynamic memory after use 
	delete [] graph[i];
	delete [] graph; 
}

 
/*

4 5
0 1
3 1
2 1
3 2
0 3 
1
3 

        Input Graph

     0------>1<-----3 
      \     /\     /  
       \    |     /       
         \  |   /      
         _\|| |/_        
		    2 
 
*/

  
/*  
  
 (V=Vertex), (E=Edge) 
 
*/





 











