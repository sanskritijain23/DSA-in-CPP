/*
Problem: GCD Sum
Platform: LeetCode Weekly Contest
Topic: Math, GCD, Sorting

Approach:
- Find the maximum element seen so far while traversing the array.
- Compute gcd(current element, current maximum) for every element.
- Store these GCD values in a new array.
- Sort the GCD array.
- Pair the smallest and largest GCD values and add their GCD to the answer.
- Repeat for all pairs.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        vector<int> prefixgcd;
        long long sum=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixgcd.push_back(__gcd(nums[i],mx));
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        for(int i=0;i<(n/2);i++){
            sum=sum+(__gcd(prefixgcd[i],prefixgcd[n-i-1]));
        }
        return sum;
    }
};