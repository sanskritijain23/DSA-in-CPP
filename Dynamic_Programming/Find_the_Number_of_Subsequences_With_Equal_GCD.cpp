/*
Problem: Find the Number of Subsequences With Equal GCD
Platform: LeetCode (#3336)
Topic: Dynamic Programming, Memoization, GCD

Approach:
- Use recursion with memoization.
- Maintain the current GCD of the first subsequence and the second subsequence.
- For every element, there are three choices:
    1. Skip the element.
    2. Add it to the first subsequence.
    3. Add it to the second subsequence.
- At the end, count only those states where:
    • Both subsequences are non-empty.
    • Their GCDs are equal.
- Store intermediate states using 3D DP.

Time Complexity: O(n × M²)
Space Complexity: O(n × M²)

where M = maximum possible value in nums (≤ 200).
*/

class Solution {
public:
    int MOD=1e9+7;
    int t[201][201][201];
    int solve(vector<int>& nums, int i, int first,int second){
        if(i==nums.size()){
            bool bothnonempty=(first!=0 && second !=0);
            bool gcdsmatch=(first==second);
            return (bothnonempty && gcdsmatch)?1:0;
        }
        if(t[i][first][second]!=-1){
            return t[i][first][second];
        }
        int skip=solve(nums,i+1,first,second);
        int take1=solve(nums, i+1,__gcd(first,nums[i]),second);
        int take2=solve(nums,i+1,first,__gcd(second,nums[i]));
        return t[i][first][second]=(0LL +skip+take1+take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);
    }
};