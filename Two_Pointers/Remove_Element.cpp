/*
Problem: Remove Element
Platform: LeetCode (#27)
Topic: Two Pointers

Approach:
- Maintain a write pointer to store elements that are not equal to the given value.
- Traverse the array using a read pointer.
- Copy only the required elements to the front of the array.
- The write pointer represents the new length of the modified array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};