/*
Problem: Sorted GCD Pair Queries
Platform: LeetCode (#3312)
Topic: Math, Number Theory, Inclusion-Exclusion, Prefix Sum

Approach:
- Count the frequency of every number.
- For each divisor i, count how many numbers are divisible by i.
- Compute the number of pairs having GCD divisible by i using nC2.
- Apply Inclusion-Exclusion (Mobius-like idea) by subtracting contributions of multiples
  to obtain the exact number of pairs whose GCD is i.
- Build a prefix sum of pair counts.
- For each query, use binary search (lower_bound) on the prefix array to find the
  corresponding GCD value.

Time Complexity: O(M log M + Q log M)
Space Complexity: O(M)

where:
M = maximum value in nums
Q = number of queries
*/


class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
         int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1);
        for (int num : nums) {
            cnt[num]++;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] += cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }
        for (int i = m; i >= 1; i--) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] -= cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans;
        for (long long q : queries) {
            q++;
            int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};