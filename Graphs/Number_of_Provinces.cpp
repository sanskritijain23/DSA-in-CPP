/*
Problem: Number of Provinces
Platform: LeetCode (#547)
Topic: Graphs, DFS

Approach:
- Convert the adjacency matrix into an adjacency list.
- Traverse each unvisited node using DFS.
- Every new DFS traversal represents a new connected component (province).
- Count the total number of connected components.

Time Complexity: O(V²)
Space Complexity: O(V²)
*/

class Solution {
public:
    void dfs(int node,vector<int> adjls[],vector<int>& vis){
        vis[node]=1;
        for(auto it:adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> adjls[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<int> vis(v,0);;
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};