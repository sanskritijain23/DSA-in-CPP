/*
Problem: Count Number of Nice Subarrays
Platform: LeetCode (#1248)
Topic: Sliding Window

Approach:
- Convert the problem into counting subarrays with at most k odd numbers.
- Count subarrays having at most k odd numbers.
- Count subarrays having at most (k - 1) odd numbers.
- Their difference gives the number of subarrays with exactly k odd numbers.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int> &nums,int k){
        if(k<0)    return 0;
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum+=(nums[r]%2);
            while(sum>k){
                sum=sum-(nums[l]%2);
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
    
};