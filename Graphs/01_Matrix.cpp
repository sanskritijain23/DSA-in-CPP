/*
Problem: 01 Matrix
Platform: LeetCode (#542)
Topic: Graphs, Multi-Source BFS

Approach:
- Push all cells containing 0 into the queue as the starting points.
- Mark them as visited with distance 0.
- Perform Multi-Source BFS to explore neighboring cells.
- The first time a cell is visited gives its shortest distance to the nearest 0.
- Store the computed distance for each cell in the result matrix.

Time Complexity: O(n × m)
Space Complexity: O(n × m)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;

                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
    }
};