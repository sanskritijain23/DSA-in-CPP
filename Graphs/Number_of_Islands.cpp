/*
Problem: Number of Islands
Platform: LeetCode (#200)
Topic: Graphs, BFS, Matrix Traversal

Approach:
- Traverse every cell of the grid.
- Whenever an unvisited land cell ('1') is found, start a BFS from it.
- Mark all connected land cells as visited.
- Each BFS represents one separate island.
- Count the number of BFS traversals to get the total islands.

Time Complexity: O(n × m)
Space Complexity: O(n × m)
*/


class Solution {
private:
    void bfs(int row,int col, vector<vector<int>>& vis,vector<vector<char>>& grid ){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delrow[4]={-1,0,1,0};
            int delcol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                
            }
        }
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};