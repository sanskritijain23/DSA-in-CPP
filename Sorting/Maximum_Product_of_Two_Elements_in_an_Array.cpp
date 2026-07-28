/*
Problem: Maximum Product of Two Elements in an Array
Platform: LeetCode (#1464)
Topic: Sorting, Greedy, Arrays

Approach:
- Sort the array in ascending order.
- The two largest elements will be at the end of the array.
- Compute (largest - 1) * (second largest - 1).
- Return the result.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return ((nums[n-1]-1)*(nums[n-2]-1));
    }
};