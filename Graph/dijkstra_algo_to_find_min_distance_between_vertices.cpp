#include <bits/stdc++.h>
using namespace std;
 
// valid only for +ve edge value graph  
// considering edge value arr[i][j] = distance between vertex i & j                                        
// (weight = value of edge) (distance[i] = distance of vertex 'i' from its parentVertex which is vertex 0 here) 
// minDistance between i & j = minDistanceOfVertex'i'FromVertex'0' - minDistanceOfVertex'j'FromVertex'0'                                   
                                                                                         
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                               // creating adjacency matrix  
	for(int i=0; i<nV; i++)  
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                 // storing weighted graph    
	{  int v1, v2, weight;
	   cin>>v1>>v2>>weight;
	   arr[v1][v2] = weight;
	   arr[v2][v1] = weight;  }
	
	return arr;
}
                                  
int minDistance_unvisitedVertex(int *distance, bool *visitedV, int nV)                 
{                                                           // calculating minDistance of eachVertex from vertex 0   
	int minV = -1;
	
	for(int i=0; i<nV; i++)
	{  if(!visitedV[i] && (minV==-1 || distance[i]<distance[minV]))
       minV = i;  }
	
	return minV;
}

void findingMinDistance_usingDijkstraAlgo(int **arr, int nV)
{  
	int *distance = new int[nV];                            // distance[i] = minDistanceOfVertex'i'FromVertex'0'   
	for(int i=0; i<nV; i++)
	distance[i] = INT_MAX;                                  // initially distance of vertex 'i' from vertex 0  is oo 

	bool *visitedV = new bool[nV];                          // vertex 'i' is already visited or not    
	for(int i=0; i<nV; i++)
	visitedV[i] = false;
	
	distance[0] = 0; 
	for(int i=0; i<nV; i++)
	{                                                       // find unvisited nearestVertex    
	   int minV = minDistance_unvisitedVertex(distance, visitedV, nV);
	   visitedV[minV] = true;
		   
	   for(int j=0; j<nV; j++)                              // exploring unvisited neighbourVertices of minVertex (which are connected to min vertex)  
	   {  if(arr[minV][j]==0 || visitedV[j])
	      continue;
		                                  
		  if(distance[minV] + arr[minV][j] < distance[j])
		  distance[j] = distance[minV] + arr[minV][j];  } 
	}                                                       // if distanceOf'j'via'minV' is least then update minDistanceOf'j'From'0'               
 
    cout<<"\n i  distance[i]"<<endl;
	for(int i=0; i<nV; i++)
	cout<<" "<<i<<"      "<<distance[i]<<endl; 
 
	delete [] visitedV;
	delete [] distance;
}
                                                                          

int main()
{ 
	int nV, nE;
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                    // storing weighted graph
	
	findingMinDistance_usingDijkstraAlgo(arr, nV);          // finding minDistance of eachVertex from vertex 0  
	
	for(int i=0; i<nV; i++)
	delete [] arr[i];
	delete [] arr; 
}

 
/*

5 7
0 1 4
0 2 8
1 2 2
1 3 5
2 3 5
2 4 9
3 4 4

*/
                            

/*  

              Input Graph 
                                                         
                      5
               (1)---------(3)
               /|         / |
           4 /  |        /  |  
           /    |    5 /    |
         (0)  2 |     /     | 4
           \    |   /       |
           8 \  |  /        |
               \|/          |              
               (2)---------(4) 
                      9
          
           
   Min distance of (each vertex) from (vertex 0)
 
                4           9 
               (1)---------(3)
               /|         / |
             /  |        /  |  
           /    |      /    |
       0 (0)    |     /     | 
           \    |   /       |
             \  |  /        |
               \|/          |              
               (2)---------(4)  
                6           13      
    
*/






 

