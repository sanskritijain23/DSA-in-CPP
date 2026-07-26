/*
Problem: Aggregate Time Series
Platform: LeetCode
Topic: Two Pointers, Arrays, Merge

Approach:
- Use two pointers to traverse both sorted time series.
- Pick the smaller timestamp among the current elements.
- Add values from both series having the same timestamp.
- Move pointers after processing their timestamps.
- Store the aggregated result.

Time Complexity: O(n + m)
Space Complexity: O(1)

where:
n = size of series1
m = size of series2
*/



class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> agg;
        int n=series1.size();
        int m=series2.size();
        int i=0,j=0;
        while(i<n || j<m){
            int t;
            if(i==n)
                t=series2[j][0];
            else if(j==m)
                t=series1[i][0];
            else
                t=min(series1[i][0],series2[j][0]);
            int v1=0,v2=0;
            if(i<n)
                v1=series1[i][1];
            if(j<m)
                v2=series2[j][1];
            agg.push_back({t,v1+v2});
            if(i<n && series1[i][0]==t)
                i++;
            if(j<m && series2[j][0]==t)
                j++;
        }
        return agg;
    }
};