/*
Problem: Maximum Valid Pair Sum
Platform: LeetCode Weekly Contest
Topic: Arrays, Prefix Maximum

Approach:
- Maintain the maximum value among all valid left indices.
- For every index j (starting from k), update the prefix maximum using nums[j - k].
- Calculate the pair sum using the current maximum left value and nums[j].
- Keep track of the maximum pair sum obtained.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int mx=nums[0];
        int ans=INT_MIN;
        for(int j=k;j<nums.size();j++){
            mx=max(mx,nums[j-k]);
            ans=max(ans,mx+nums[j]);
        }
        return ans;
    }
};