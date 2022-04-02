
/*package whatever //do not write package name here */

import java.io.*;
class Graph{
    private int V;// NO OF VERTICES
    private LinkedList<Integer> adj[];
    
    Graph(int v){
        V=v;
        adj= new LinkedList[v];
        for(int i=0; i<n;i++){
            adj[i]= new LinkedList();
        }
    }
    
    void addEdge(int v, int w){
        add[v].add(w);
    }
    
    void BFS(int s){
        boolean visited[]= new boolean[V];
        // craete a queue for  BFS
        // it by default mark all the vertices as not vivited i.e by defalut mark them as false 
        LinkedList<Integer> queue= new LinkedList<Integer>();
        
        
        // si our current vertices : marked it as visited and enqueue it 
        visited[s]= true;
        queue.add(s);
        
        while(queue.size()!=0){
            
            s=queue.poll();// linked list me se remove karvaane k liye
            System.out.print(s+" ");
            
            Iterator<Integer>it = adj[s].listIterator();// iterator to get the adjacent vertices of the dequqed vertex s 
            // if the adjacent vertices has not been vivisted , then mark it visited and enque it 
            while (i.hasNext())
            {
                int n =it.next;
                if(!visited[n]){
                    visited[n]=true;
                    queue.add(n);
                }
            }
        }
        
        
    }
    
}

class GFG {
	public static void main (String[] args) {
		System.out.println("GfG!");
	}
}