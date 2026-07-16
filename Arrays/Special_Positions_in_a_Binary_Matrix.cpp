/*
Problem: Special Positions in a Binary Matrix
Platform: LeetCode (#1582)
Topic: Matrix, Arrays, Counting

Approach:
- Count the number of 1s present in every row and every column.
- Traverse the matrix again.
- A cell is special if:
    • The cell value is 1.
    • Its row contains exactly one 1.
    • Its column contains exactly one 1.
- Count all such special positions.

Time Complexity: O(n × m)
Space Complexity: O(n + m)
*/


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> rowcount(n,0);
        vector<int> colcount(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    rowcount[i]++;
                    colcount[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(rowcount[i]==1 && colcount[j]==1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};