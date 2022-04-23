#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

#define V 6

bool bfs( int rGraph[V][V] , int s, int t, int parent[]){
    bool visited[V];// will keep track of visited vertices 
    memset(visited,0,sizeof(visited));

    // create a queue , enqueue the source vertex and mark the vsited to be true 
    queue<int> q;// NICE!! we dont have to tell the size of queue
    q.push(s);
    visited[s]=true;
    parent[s]=-1

    while(!q.empty()){
        int u =q.front();
        q.pop;

        for(int v=0; v<V; v++){
            if(visited==false && rGraph[u][v] >0){// we always want our residual capacity to be more than zero

                if(v==t){// agar aise krte krte , we have reached our target node
                    parent[v] =u;
                    return true;
                }

                q.push();
                parent[v]=u;
                visited[v]=true;
                
            }
        }
    }


    return false;

}
int finfMaxFlow(int graph[V][V], int s, int t){
    int rGraph[V][V];
    int u, v;

    for( u=0;u<V; u++){
        for(v=0; v<V;v++){// because initilay resildual capcity at any edge eill be equal to capacity at that edge
            rGraph[u][v]=graph[u][v];
        }
    }

    int parent[V]; // this  will store abhi tak jo path flow h graph me 
    int maxFlow;

    while( bfs(rGraph,s,t,parent)){
        // now we need to maximise the residual capcity => indirectlt increasing the flow through that edge 

        int path_flow= INT_MAX;

        for (v=t ; v!=s; v=parent[v]){
            u=parent[v];
            path_flow= min(path_flow, rGraph[u][v]);
            }


        // update the residual capcacities of the edges and reverse the edges with capcity equal to the flow in forward edge 

        for ( v=t; v!=s; v=parent[v]){
            u= parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u] += path_flow;
        }
 }
    return maxFlow;
    
}
int main() {
    cout<<"Hello World!";
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
 
    return 0;

}
