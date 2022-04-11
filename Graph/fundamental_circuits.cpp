#include <bits/stdc++.h>
using namespace std;
 
// considering edge value arr[i][j] = distance between vertex i & j                                        
// to print final MST, we wil use concept of parent vertex (printing by travelling from last vertex)   
// (weight = value of edge) (distance[i] = distance of vertex 'i' from its parentVertex / itsNearestVertex whichIsAlreadyVisited)                                   
                                                                                       
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                          // creating adjacency matrix                            
	for(int i=0; i<nV; i++)                            // arr[nV][nV]
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                            // storing weighted graph                     
	{  int v1, v2, weight;
	   cin>>v1>>v2>>weight;
	   arr[v1][v2] = weight;
	   arr[v2][v1] = weight;  }
	
	return arr;
}

int c = 1;                                             // count of fundamental circuits
  
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
 
void printFundamentalCycle(int **arr, int nV)
{
	bool visitedV[nV] = {0};
	vector<int> dfs;
	
	bool r = findCycleDFS(0, -1, arr, nV, visitedV, dfs);
	
	if(r==false)
	return;
	
    int sourceV = dfs[dfs.size()-1]; 
 	cout << "Cycle_" << c << ": " << sourceV << " "; 
 	
	for(int i=dfs.size()-2; i>=0; i--) 
	{ 
	    cout << dfs[i] << " ";
	    
		if(dfs[i]==sourceV)
		break;	 
    }
    cout << endl;
    c++;
}
 
int minDistance_unvisitedVertex(int *distance, bool *visitedV, int nV)
{
	int minV = -1;
	
	for(int i=0; i<nV; i++)
	{  if(!visitedV[i] && (minV==-1 || distance[i]<distance[minV]))
       minV = i;  }
	
	return minV;
}

void findingMST_usingPrimsAlgo(int **arr, int nV, int nE)
{ 
	int *parentV = new int[nV];                        // parentVertex / nearestVertexFromVertex'i' whichIsAlreadyVisited               
	for(int i=0; i<nV; i++)
	parentV[i] = -1;
	
	int *distance = new int[nV];                       // distance[i] = distanceOfVertex'i' from parentVertex / nearestVertex whichIsAlreadyVisited
	for(int i=0; i<nV; i++)
	distance[i] = INT_MAX;                             // initially parentVertex of each vertex is at infinity 

	bool *visitedV = new bool[nV];                     // vertex 'i' is already visited or not                                    
	for(int i=0; i<nV; i++)
	visitedV[i] = false;
	                                                                                                                                                                
	distance[0] = 0;                                   // starting the traversal for MST from vertex 0                          
	parentV[0] = -1;
	for(int i=0; i<nV; i++)
	{                                                  // find unvisited nearestVertex                                                                                       
	   int minV = minDistance_unvisitedVertex(distance, visitedV, nV);
	   visitedV[minV] = true;                            
		                                                                                
	   for(int j=0; j<nV; j++)                         // making minVertex as parent of unvisited neighbourVertices if itIsNearestToThem  
	   {  if(arr[minV][j]==0 || visitedV[j])
	      continue;
		                                  
		  if(arr[minV][j] < distance[j])
		  {  parentV[j] = minV;
		     distance[j] = arr[minV][j];  }
	   }
	} 
	         
    cout<<"\n\nMST:"<<endl;
	for(int i=1; i<nV; i++)                                 
	{   
	    if(parentV[i] < i)                             // printing smaller vertex first  
	    cout<<parentV[i]<<" "<<i<<" "<<distance[i]<<endl;
	    else 
		cout<<i<<" "<<parentV[i]<<" "<<distance[i]<<endl; 
	} 
	 
	int **arr_MST = new int*[nV];                      // creating adjacency matrix                            
	for(int i=0; i<nV; i++)
	{  arr_MST[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr_MST[i][j] = 0;	}
	
	for(int i=1; i<nV; i++)                            // storing MST in adjacency matrix                                     
	{  int v1 = parentV[i];
	   int v2 = i;
	   int weight = distance[i];
 
	   arr_MST[v1][v2] = weight;
	   arr_MST[v2][v1] = weight;  }
	
	cout<<"\nNo of fundamenta circuits: "<<nE-nV+1<<endl;
	cout<<"\nFundamental circuits of given graph: "<<endl;
	for(int i=0; i<nV; i++)
	{  for(int j=i; j<nV; j++)             
	   {   
	      if(arr[i][j]>0 && arr_MST[i][j]==0)
	      {  
		      arr_MST[i][j] = arr[i][j]; 
	      	  arr_MST[j][i] = arr[j][i]; 
	      	  
	      	  printFundamentalCycle(arr_MST, nV);
	      	    
	      	  arr_MST[i][j] = 0; 
	      	  arr_MST[j][i] = 0;      
	      }
       }
    } 
}
 

int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);               // storing weighted graph
	
	findingMST_usingPrimsAlgo(arr, nV, nE);
	
	for(int i=0; i<nV; i++)
	delete [] arr[i];
	delete [] arr;  
}
 
 
/*
                                                                                                
6 11
0 1 1
0 2 2
0 3 12
1 2 3
1 3 6
2 3 7
2 4 5
2 5 8
3 4 10
3 5 9  
4 5 4
                                                                     
*/

 
/* 

 Input Weighted Graph    (Vertices = {0,1,2,3,4,5})        

          1 
    0-----------1
    |\        / |
	|  \12  /   |  
   2|    \/     |6
    |    /\     |
    |  /3   \   |
    |/        \ |              
    2-----7-----3
    |\        / |
	|  \8   /   |  
   5|    \/     |9
    |    /\     |
    |  /10  \   | 
    |/        \ |
    4-----------5
          4
        
    
Minimum Spanning Tree (MST)
 
          1 
    0-----------1
    |           |
	|           |  
   2|           |6
    |           | 
    |           |              
    2           3
    | 
	|  
   5|        
    |  
    | 
    4-----------5
          4
                                                    
*/







 







