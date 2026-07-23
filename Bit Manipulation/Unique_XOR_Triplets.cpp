/*
Problem: Unique XOR Triplets
Platform: LeetCode
Topic: Bit Manipulation, Math

Approach:
- If the array contains only 1 or 2 elements, the number of unique XOR triplets
  is equal to the number of elements.
- For n >= 3, observe that every XOR value from 0 to the smallest power of two
  greater than n can be generated.
- Compute the smallest power of two strictly greater than n and return it.

Time Complexity: O(log n)
Space Complexity: O(1)
*/


class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2)
            return n;
        int ans=1;
        while(ans<=n){
            ans*=2;
        }
        return ans;
    }
};