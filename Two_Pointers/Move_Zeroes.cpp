/*
Problem: Move Zeroes
Platform: LeetCode (#283)
Topic: Two Pointers

Approach:
- Count the number of zeroes in the array.
- Store all non-zero elements in a temporary vector.
- Append the counted zeroes at the end.
- Copy the modified array back to the original array.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int numzeroes=0;
        for(int i=0;i<n;i++){
            numzeroes+=(nums[i]==0);

        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
        }
        while(numzeroes--){
            ans.push_back(0);
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};