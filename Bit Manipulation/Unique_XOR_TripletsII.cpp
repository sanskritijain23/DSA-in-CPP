/*
Problem: Unique XOR Triplets
Platform: LeetCode
Topic: Bit Manipulation, XOR

Approach:
- Find all possible XOR values of pairs (nums[i] ^ nums[j]).
- Store these values in a boolean array to remove duplicates.
- For every possible pair XOR value, combine it with every number in nums.
- Store all possible triplet XOR results.
- Count the number of unique XOR values obtained.

Time Complexity: O(n^2 + n * m)
Space Complexity: O(m)

where:
n = size of nums
m = range of possible XOR values.
*/


class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxel=*max_element(begin(nums),end(nums));
        int t=1;
        while(t<=maxel){
            t<<=1;
        }
        vector<bool> s1(t,false);
        vector<bool> s2(t,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<t;i++){
            if(s1[i]==true){
                for(int &num:nums){
                    s2[i^num]=true;
                }
            }
        }
        int count=0;
        for(int i=0;i<t;i++){
            if(s2[i]==true){
                count++;

            }
        }
        return count;
    }
};