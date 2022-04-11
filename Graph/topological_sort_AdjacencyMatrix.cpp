#include<iostream> 
using namespace std;

 
int** storeGraph(int nV, int nE)
{
	int **graph = new int*[nV];                                                            
	for(int i=0; i<nV; i++)
	{  graph[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   graph[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                                
	{  int v1, v2;
	   cin>>v1>>v2;
	   graph[v1][v2] = 1;	 }
	
	return graph;
}

template <typename T>
class StackUsingArray                                  // implementing stack using array & template                              
{  
   T *data;
   int nextIndex;
   int capacity;
   
     public:
   StackUsingArray()
   {  data = new T[4];
      nextIndex = 0;
	  capacity = 4;  }	
	
   int size()
   {  return nextIndex;  }
   
   bool isEmpty()
   {  return  (nextIndex==0);  }
   	
   void push(T x)
   {  if(nextIndex==capacity)
   	  {  T *arr = new T[2*capacity];                   // double stack capacity when stack is full
   	     for(int i=0; i<capacity; i++)
   	     arr[i] = data[i];
   	     
   	     capacity *= 2;  
		 delete []data;
		 data = arr;  }
   	  
   	  data[nextIndex] = x;
   	  nextIndex++;   }	
	
   T pop()
   {  if(isEmpty())
   	  {  cout<<"Stack is empty"<<endl;
   	     return 0;  }
   	
   	  nextIndex--;
   	  return data[nextIndex];   }	
	
   T top()
   {  if(isEmpty())
      {  cout<<"Stack is empty"<<endl;
         return 0;  }
	   
   	  return data[nextIndex-1];   }	 
};

 
 
void sort(int **graph, int nV, int u, bool visitedV[], StackUsingArray<int> &s) 
{
   visitedV[u] = true;               

   for(int v=0; v<nV; v++) 
   {
      if(graph[u][v] > 0) 
	  {             
         if(!visitedV[v])
         sort(graph, nV, v, visitedV, s);
      }
   }
   
   s.push(u);      
}

void topologicalSort(int **graph, int nV) 
{
   StackUsingArray<int> s;
   bool visitedV[nV];

   for(int i=0; i<nV; i++)
   visitedV[i] = 0;    

   for(int i=0; i<nV; i++)
   {
	   if(!visitedV[i])     
       sort(graph, nV, i, visitedV, s);
   }

   while(!s.isEmpty()) 
   {
      cout << s.top() << " ";
      s.pop();
   }
}

main() 
{
	int nV, nE;
	cin>>nV>>nE;
	int **graph = storeGraph(nV, nE);                                 

   cout << "\nTopological Sorted order of vertices: ";
   topologicalSort(graph, nV);
   cout<<endl;
	 
   for(int i=0; i<nV; i++)                               // deleting the dynamic memory after use 
   delete [] graph[i];
   delete [] graph; 
}


/*
 
6 6
5 0
5 2
2 3
3 1
4 1
4 0
 
           Input Graph

     5------>0<-----4----->1 
      \                    |
       \                   |
         \                 |
         _\|               |
		    2------------->3
 
*/









