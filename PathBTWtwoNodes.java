/*package whatever //do not write package name here */

import java.io.*;

class Graph{
    int V;// no of Vertices 
    
    ArrayList<ArrayList<Integer>> adj;// adjacency list of vertices
    Graph(int v){
        this.V=v;
        adj= new ArrayList<>();
        for(int i=0;i<V;i++){
            adj.add(new ArrayList<>());        }
        
    }
    
    
    void addEdge(int v, int w){
        adj.get(v).add(w);
        adj.get(w).add(v);
        
    }
    
    boolean isReachable (int s, int d){
        for(int i=0;i<V;i++){
            visited[i]=false;// vase by default bhi false hot hai System
            
        }
        // queue for BFS
        
        
        Queue<Integer> q= new LinkedList<>();
        
        visited[s]=true;
        q.add(s);
         while(!q.isEmpty()){
             s=q.remove;// dequue a vertex from the queue to print it 
             
             
             
             // get all the adjacent vertices of the dequued vertex s 
             //if the adjacent vertex have not been viisted , then mark it 
             // visited   and enequue it 
             for(int i=0;i<ad.get(s).size();i++){
                 
                 
                 // if the adjacent node is the destination node
                 // then return true// case 1
                 if(adj.get(s).get(i)==d){
                     return true;
                 }
                 
                 // case 2 
                 // follow BFS
                 // continue to do BFS 
                if(!visited[adj.get[s].get(i)]){
                         visited[adj.get(s).get(i)]=true;
                         queue.add(adj.get(s).get(i));
                }_
                     
            }   
                 
        }
        // if BFS is complte without finding/ visiting  d then return false
        return false;
        
         }
        
    }


class GFG {
	public static void main (String[] args) {
		System.out.println("GfG!");
	}
}