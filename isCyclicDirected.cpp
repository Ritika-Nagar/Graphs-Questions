#include <iostream>
using namespace std;


bool isCyclic_util(vector<int> adj, vector<bool> vis, int curr){
    if(vis[curr]==true){
        return true;
    }
    
    vis[curr]=true;
    bool FLAG= false;
    
    for(int i=0; i<adj[curr].size();++i){
        FLAG= isCyclic_util(adj, vis, adj[curr][i]);
        if(FLAG==true)
        return true;
    }
    return false;
    
    
    
    
    
}
bool isCyclic( int v, vector<int>adj){
    
    vector<bool> visited(v,false);
    bool FLAG= false;
    
    for(int i=0;i<V;++i)
    {
        visited[i]=true;
        for(int j=0; j< adj[i].size();++j){
            FLAG=isCyclic_util(adj, visited, adj[i][j]);
            if(FLAG==true){
               return true; 
            }
            
            visited[i]=false;// backtrack karo
            
        }
        return false;
    }
}
int main() {
	int v, e;
	cin>>v>>e;
	 vector<int> g[v];
	 
	 for(int i=0;i<e;i++){
	     int u, v;
	     cin>>u>>v;
	     // becuase it is directed graph
	      g[u].push_back(v);
	 }
	 cout << isCyclic(v,g)<< endl;
	 return 0;
}