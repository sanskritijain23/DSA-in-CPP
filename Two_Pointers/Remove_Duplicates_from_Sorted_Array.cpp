/*
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode (#26)
Topic: Two Pointers

Approach:
- Maintain two pointers: one for the last unique element and one for traversal.
- Compare the current element with the last unique element.
- If they are different, move the unique pointer forward and overwrite the next position.
- The final position of the unique pointer gives the length of the unique array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};