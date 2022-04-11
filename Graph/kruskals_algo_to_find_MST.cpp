#include <bits/stdc++.h>
using namespace std;


class Edge
{     public:
	int startV;                                       // starting vertex of edge (v1)     
	int endV;                                         // ending vertex of edge (v2)        
	int weight;                                       // weight of edge                  
};

Edge* storeInputGraph(int nE)
{
	Edge *arr = new Edge[nE];                         // creating edge class array              
 
	for(int i=0; i<nE; i++)                           // taking input 
	{  int v1, v2, w;
	   cin>>v1>>v2>>w;                             
	   arr[i].startV = v1;                            // arr[i] = current edge of input graph          
	   arr[i].endV = v2;
	   arr[i].weight = w;  }
	
	return arr;
}

bool compare(Edge e1, Edge e2)
{   return (e1.weight < e2.weight);   }

int findRootParent(int currV, int *parentV)
{
	if(currV==parentV[currV])
	return currV;
	
	int r = findRootParent(parentV[currV], parentV);
	
	return r;
}

void findingMST_usingKruskalsAlgo(Edge *arr, int nV, int nE)
{
	sort(arr, arr+nE, compare);                       // i.e. sort "Edge class array arr" on the basis of "weights" using "compare function"
	Edge *arr_MST = new Edge[nV-1];
	
	int *parentV = new int[nV];                       // to apply union find approach       
	for(int i=0; i<nV; i++)
	parentV[i] = i;
	
	for(int nE_MST=0,i=0;  nE_MST!=nV-1;  i++)        // check if we can add current edge in MST (connected & no cycle) or not      
	{                                                 // arr[i] = current edge of input graph      
	   int startV_rp = findRootParent(arr[i].startV, parentV);   
	   int endV_rp = findRootParent(arr[i].endV, parentV); 
		                                                  
	   if(startV_rp != endV_rp)                       // arr_MST[i] = current edge of input graph               
	   {  arr_MST[nE_MST] = arr[i];                   // nE_MST = current no of edges in MST   
	      nE_MST++;
	      parentV[startV_rp] = endV_rp;  }
	} 
 
    cout<<"\nMST:"<<endl;                                                  
	for(int i=0; i<nV-1; i++)
	{   
	    if(arr_MST[i].startV < arr_MST[i].endV)       // printing smalller vertex first                   
	    cout<<arr_MST[i].startV<<" "<<arr_MST[i].endV<<" "<<arr_MST[i].weight<<endl;
	    else 
		cout<<arr_MST[i].endV<<" "<<arr_MST[i].startV<<" "<<arr_MST[i].weight<<endl; 
	} 
}
 

int main()
{ 
	int nV, nE;
	cin>>nV>>nE;                                      // storing input graph in array of Edge class              
	Edge *arr = storeInputGraph(nE);
	
	findingMST_usingKruskalsAlgo(arr, nV, nE);
	
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

    Input Graph

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
          
          
 Minimum Spanning Tree 
 
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






 

