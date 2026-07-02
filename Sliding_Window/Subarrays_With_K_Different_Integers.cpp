/*
Problem: Subarrays with K Different Integers
Platform: LeetCode (#992)
Topic: Sliding Window

Approach:
- Count subarrays having at most k distinct integers.
- Count subarrays having at most (k - 1) distinct integers.
- The difference gives the number of subarrays with exactly k distinct integers.
- Use a frequency map to maintain the count of distinct elements in the current window.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/

class Solution {
public:
    int func(vector<int> & nums, int k){
        int l=0,r=0,cnt=0;
        map<int,int> mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)    mpp.erase(nums[l]);
                l++;

            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (func(nums,k)-func(nums,k-1));
    }
};
