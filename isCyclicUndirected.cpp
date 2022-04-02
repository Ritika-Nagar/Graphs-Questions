#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

bool isCyclic_util(vector<int> adj, vector<int> visited, int curr){
    if(visited[curr]==2){// visited + processed
        return true;
    }
    
    visited[curr]=1;// visiting the elementsin adjacency list
    
    for(int i=0;i<adj[curr].size();++i){
        
        if(visited[adj[curr][i]==1]){
            visited[adj[curr][i]]=2;
        }
        else{
            if(isCyclic_util(adj, visited, adj[curr][i]))
                return true;
        }
    }
    
    return false;
}








bool isCyclic(vector<int> adj, int v){
    vector<int> visited[v];
    for(int i=0;i<v;++i){
        visited[i]=1;
        for(j=0;j<adj[i].size();++j){
            
            if(isCyclic_util(adj, visited,adj[i][j])){// recursive call in order to process the adjacent elements 
                return true;
            }
            
            
        } 
        visited[i]=0;//??????
        
    }
    return false;
}
int main() {
	
	int T;
	cin>>T;
	while(T--){
	int v,e;
	cin>>v>>e;
	
	vector<int> adj[v];
	
	int u,v;
	for(int i=0;i<e;i++){
	    cin>>u>>v;
	    adj[u].push_back(v);// |0| ->1->2
	    adj[v].push_back(u);
	    
	}
	cout<< isCyclic(adj,v)<< endl;
	}
}