#include <bits/stdc++.h>
using namespace std;
 
 // Connected Graph = each 2 vertex have atleast 1 path between them          
 // Disconnected Graph = have some connected subgraph or connected components 

int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                                 // creating adjacency matrix   
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                   // taking input   
	{  int v1, v2;
	   cin>>v1>>v2;
	   arr[v1][v2] = 1;
	   arr[v2][v1] = 1;	 }
	
	return arr;
}
                                                                                               
void graphTraversalDFS(int **arr, int nV, int currV, bool *visitedV)
{ 
	visitedV[currV] = true;
	
	for(int i=0; i<nV; i++)
	{  if(arr[currV][i]==0 || visitedV[i])
	   continue;
   
       graphTraversalDFS(arr, nV, i, visitedV);   }
}

void isGraphConnected(int **arr, int nV)
{
	if(nV==0)
	{  cout<<"true"<<endl;
	   return; 	}
	
	bool visitedV[nV] = {false};
	graphTraversalDFS(arr, nV, 0, visitedV);
	
	for(int i=0; i<nV; i++)
	{
	   if(!visitedV[i])                                       // unvisited vertex found means disconnected graph                                                          
	   {  cout<<"false"<<endl;
	      return;  } 
	} 
	
	cout<<"true"<<endl;
	return; 	
}
                 
void subgraphTraversalDFS(int **arr, int nV, int currV, vector<int> &vtr, bool *visitedV)
{
	vtr.push_back(currV);
	visitedV[currV] = 1;
	
	for(int i=0; i<nV; i++)
	{
	   if(arr[currV][i]==1 && !visitedV[i])
	   subgraphTraversalDFS(arr,nV,i,vtr,visitedV);
    }
}
                            
void printConnectedComponents(int **arr, int nV)          
{
	if(nV==0)
	return;
	                                    
	bool visitedV[nV] = {false};                              // storing that vertex [i] is already visited or not 
	vector<vector<int>> subgraphList;                         // storing connected components in 2D vector                      
	for(int i=0; i<nV; i++)
	{  
	   if(!visitedV[i])
	   {  vector<int> vtr;
	      subgraphTraversalDFS(arr,nV,i,vtr,visitedV);
	      subgraphList.push_back(vtr);  } 	 
	}
	
	for(int i=0; i<subgraphList.size(); i++)                  // printing connected components from 2D vector 
	{  
	   sort(subgraphList[i].begin(), subgraphList[i].end());  // printing vertices in sorted order                       
	
	   for(int j=0; j<subgraphList[i].size(); j++) 
	   cout<<subgraphList[i][j]<<" ";
	   cout<<endl;  
	} 
}
                 
void subgraphTraversalDFS(int **arr, int nV, int currV, bool *visitedV)
{ 
	visitedV[currV] = 1;
	
	for(int i=0; i<nV; i++)
	{
	   if(arr[currV][i]==1 && !visitedV[i])
	   subgraphTraversalDFS(arr,nV,i,visitedV);
    }
}
                            
void countingConnectedComponents(int **arr, int nV)
{
	if(nV==0)
	{  cout<<0<<endl;
	   return;  }
	                      
	int count = 0;              
	bool visitedV[nV] = {0}; 
	for(int i=0; i<nV; i++)
	{  
	   if(!visitedV[i]) 
	   {  subgraphTraversalDFS(arr,nV,i,visitedV);
	      count++;  } 	                                      // counting connected subgraphs              
	}
 
	cout<<count<<endl;
}


int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                      // storing graph in Adjacency Matrix  
	
	cout<<"\nIs graph connected: ";                                             
	isGraphConnected(arr, nV);                                // checking graph is connected or not 
	
	cout<<"\nConnected components are:\n";
	printConnectedComponents(arr, nV);                        // printing all connected components in graph                    
	
	cout<<"\nNo of connected components: ";
	countingConnectedComponents(arr, nV);                     // printing the count of connected components in graph  
	
	for(int i=0; i<nV; i++)                                   // deleting the memory after use
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

*/


/*  
      Input Graph
                  0
      2           |
     /\           1
    /  \          /\
   4----5        /  \
                6    3
                     |
                     7
 
*/







 
