/*
Problem: Find Greatest Common Divisor of Array
Platform: LeetCode (#1979)
Topic: Math, GCD

Approach:
- Find the minimum and maximum element in the array.
- Compute the GCD of these two values using the built-in __gcd() function.
- Return the computed GCD.

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        return (__gcd(mn,mx));
    }
};