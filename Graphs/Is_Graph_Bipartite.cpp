/*
Problem: Is Graph Bipartite?
Platform: LeetCode (#785)
Topic: Graphs, DFS, Graph Coloring

Approach:
- Initialize all vertices with color -1 (uncolored).
- Traverse every connected component using DFS.
- Assign alternating colors (0 and 1) to adjacent vertices.
- If an adjacent vertex already has the same color, the graph is not bipartite.
- If all components are successfully colored, return true.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/


class Solution {
private:
    bool dfs(int node,int col, vector<int>& color, vector<vector<int>>& adj){
        color[node]=col;
        for(auto it: adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false)    return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false)   return false;
            }
        }
        return true;
    }
};