/*
Problem: Maximum Digit Range Sum
Platform: LeetCode Weekly Contest
Topic: Math, Digit Manipulation

Approach:
- Compute the digit range (maximum digit - minimum digit) for each number.
- Find the maximum digit range among all numbers.
- Sum all numbers whose digit range equals the maximum digit range.

Time Complexity: O(n × d)
Space Complexity: O(d)
*/

class Solution {
public:
    int diff(int num){
        string s=to_string(num);
        char mx=s[0];
        char mn=s[0];
        for(char c:s){
            if(c>mx)    mx=c;
            if(c<mn)    mn=c;
        }
        return int(mx-mn);
    }
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int range=0;
        int sum=0;
        for(int i=0;i<n;i++){
            range=max(range,diff(nums[i]));
        }
        for(int i=0;i<n;i++){
            if(diff(nums[i])==range){
                sum+=nums[i];
            }
        }
        return sum;
    }
};