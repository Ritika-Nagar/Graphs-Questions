#include <iostream>
using namespace std;

struct Edge{
    int src;
    int dst;
    int weight;
};

struct Graph {
    int V, E;

    struct Edge* edge;// struct are value type: val type hold their value in memeory where they declared 
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph= new Graph;// have craeted graph type object 
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];// Edge type ke object ko memry di gyi h heap me

    return graph;

};

void BellmanFord(struct Graph* graph, int src){
    int V= graph->V;
    int E=graph->E;

    int dist[V];// it will store the distnace of vert from src


    // Initialising the dist of all vertices with infinity
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX
    dist[src]=0;// src ka dist is 0

    // Relax/ Update all the edges (V-1)
    //** A simple shortest path from src to any other vertex can have atmost V-1 EDGES

    for(int i=1; i<V;i++){
        for(int j=0; j<E;j++){// ek particular vertex k corresponding jitne bhi edges h vo nikaal lo  
            int u= graph->edge[j].src;
            int v= graph-> edge[j].dest;
            int weight= graph->edge[j].weight;

            if(dist[u] !INT_MAX && dist[u]+weight< dist[v])
                dist[v]=dist[u]+weight;
        }
    } 


    // In order to detect the negaive weight cycle in the graph 

    for(int j=0; j<E;j++){
        int u= graph->edge[j].src;
            int v= graph-> edge[j].dest;
            int weight= graph->edge[j].weight;

            if(dist[u] !INT_MAX && dist[u]+weight< dist[v])
                cout<< "Graph contains negative cycle"<<endl;
                return;// if graph contains negative cyle then simple return

    }



















    }




}
int main() {
    
}
