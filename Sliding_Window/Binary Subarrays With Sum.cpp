/*
Problem: Binary Subarrays With Sum
Platform: LeetCode (#930)
Topic: Sliding Window

Approach:
- Count subarrays having sum at most goal.
- Count subarrays having sum at most (goal - 1).
- Their difference gives the number of subarrays with sum exactly equal to goal.
- Use a variable-size sliding window since all elements are non-negative.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, sum = 0, cnt = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};