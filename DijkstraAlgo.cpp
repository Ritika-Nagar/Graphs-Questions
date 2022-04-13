#include <iostream>
using namespace std;
#include <limits.h>

# define V 9 // no of vertices 

// a function to find the vertex with min distance and has not been processed 

int minDist( int dist[], bool sptset[]){

  int min =INT_MAX;
  int min_indx;
  for(int v=0;v<V; v++){
    if(sptset[v]==false && dist[v]<=min)
      min=dist[v];
      min_indx=v;
  }
  return min_indx;
}

// print solution 
void print(int dist[]){
  cout<< "Vertex \t Distance from Source"<< endl;
  for(int i=0 ;i < V; i++){
    cout<< i << "\t\t" << dist[i] << endl;
  }
}
void dijkstra(int graph[V][V], int src){
  int dist[V];
  bool sptset [V];// this will keep track of processed vertices 

  for(int i=0; i<V;i++){
    dist[i]=INT_MAX, sptset[i]=false;
  }
  dist[src]=0;// source ka distance is always 0


  // finding shortest path 
  // count is calculating the value of shortest distance 
  for(int count =0; count <V-1; count++){

    // pick the vertex which is not processed and has min distance 

    int u= minDist(dist, sptset);

    sptset[u] =true;// vertec have been processed 

    for( int v=0 ;v < V;v++){
      // think as if there is path from u ->v
      // update dist[v] only if it is not in sptset# sptset[v]=false , there should be an 
      // edge from u -> v, i.e dist!=0, and total weight of path from src to v 
      //through u is smaller than the current value of dist[v]

      if(!sptset[v] && graph[u][v] && dist[u] !=INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] =dist[u] +graph[u][v];
      
    }
    
  }

}


int main(){
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    
  return 0;
}