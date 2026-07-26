/*
Problem: Maximum Product of Three Numbers
Platform: LeetCode (#628)
Topic: Greedy, Arrays

Approach:
- Track the three largest numbers while traversing the array.
- Track the two smallest numbers because two negative numbers can create a large positive product.
- The maximum product can be:
    1. Three largest numbers.
    2. One largest number and two smallest numbers.
- Return the maximum of these two possibilities.

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int small1 = INT_MAX, small2 = INT_MAX;

        for (int x : nums) {
            if (x >= first) {
                third = second;
                second = first;
                first = x;
            }
            else if (x >= second) {
                third = second;
                second = x;
            }
            else if (x >= third) {
                third = x;
            }

            if (x <= small1) {
                small2 = small1;
                small1 = x;
            }
            else if (x <= small2) {
                small2 = x;
            }
        }

        return max(first * second * third,
                   first * small1 * small2);
    }
};