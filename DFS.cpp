#include <iostream>
using namespace std;

int main() {
	cout<<"GfG!";
		int N, E;// N is #Vertices
	// E is #Edges
	cin>> N>>E;
	
	vector<int> g[N];// adjacency list 
	bool visited[N];
	memset(visited, false, sizeof(visited));
	
	for(int i=0; i<E;i++)
	{
	   int u,v;
	   cin>>u>>v;
	   // only in case of undirected graph 
	   g[u].push_back(v);
	   g[v].push_back(u);
	}
	dfs(0,g,visited);
	cout << endl;
	return 0;
}

void dfs(int s, vector<int>g, bool *vis){
    vis[s]=true;
    
    cout<<s<<" ";
    
    for(int i=0;i<g[s].size();++i){
        if(vis[g[s][i]]==false)
        {
            dfs(g[s][i],g, vis);
        }
    }
}
