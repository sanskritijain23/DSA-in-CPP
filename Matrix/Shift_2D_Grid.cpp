/*
Problem: Shift 2D Grid
Platform: LeetCode (#1260)
Topic: Matrix, Simulation

Approach:
- Treat the 2D grid as a flattened 1D array.
- Compute the current index of each element.
- Shift the index by k positions using modulo arithmetic.
- Convert the new index back to 2D coordinates.
- Place the element in its new position.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        k%=total;
        vector<vector<int>> ans(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int currindex=i*n+j;
                int newindex=(currindex+k)%total;

                int newrow=newindex/n;
                int newcol=newindex%n;

                ans[newrow][newcol]=grid[i][j];
            }
        }
        return ans;
    }
};