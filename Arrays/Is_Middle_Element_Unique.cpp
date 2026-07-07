/*
Problem: Is Middle Element Unique
Platform: LeetCode Weekly Contest
Topic: Arrays

Approach:
- Find the middle element of the array.
- Traverse the entire array and count its occurrences.
- If the middle element appears more than once, return false.
- Otherwise, return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        int i=n/2;
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==nums[i]){
                count++;
            }
        }
        if(count>1){
            return false;
        }
        return true;
    }
};
