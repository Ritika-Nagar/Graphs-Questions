#include <iostream>
using namespace std;

class Solution {
public:
    void mark_curr_islands(vector<vector<char>>& grid,int x, int y, int r, int c){
        
        
        if(x<0 || x>=r|| y<0 || y>=c || grid[x][y] !='1')
            return ;
        
        // mark the current cell as visited
        grid[x][y]='2';
        
        mark_curr_islands(grid,x+1,y,r,c);
        mark_curr_islands(grid,x,y+1,r,c);
        mark_curr_islands(grid,x-1,y,r,c);
        mark_curr_islands(grid,x,y-1,r,c);
        
        
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        
        if(rows==0)
            return 0;
        
        int cols= grid[0].size();
        int no_of_islands=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                
                if(grid[i][j]=='1'){
                    mark_curr_islands(grid,i,j,rows,cols);
                    no_of_islands+=1;}
            }
        }
        return no_of_islands;
    }
};