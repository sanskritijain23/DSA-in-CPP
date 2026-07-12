/*
Problem: Flood Fill
Platform: LeetCode (#733)
Topic: Graphs, DFS

Approach:
- Store the original color of the starting pixel.
- If the original color is the same as the new color, return the image.
- Perform DFS from the starting cell.
- Recolor every connected cell having the original color.
- Explore all four directions recursively.

Time Complexity: O(n × m)
Space Complexity: O(n × m)    // Recursive call stack in the worst case
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int oldcolor, int newcolor){
        int n=image.size();
        int m=image[0].size();
        image[row][col]=newcolor;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==oldcolor){
                dfs(nr,nc,image,oldcolor,newcolor);

            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor=image[sr][sc];
        if(oldcolor==newColor){
            return image;
        }
        dfs(sr,sc,image,oldcolor,newColor);
        return image;
    }
};