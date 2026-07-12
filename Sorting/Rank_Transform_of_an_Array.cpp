/*
Problem: Rank Transform of an Array
Platform: LeetCode (#1331)
Topic: Sorting, Hashing

Approach:
- Create a copy of the original array and sort it.
- Assign ranks to unique elements in increasing order.
- Store the mapping of element → rank using a map.
- Replace every element in the original array with its assigned rank.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums(arr);
        sort(nums.begin(),nums.end());
        map<int,int> numtorank;
        int rank=1;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]>nums[i-1]){
                rank++;
            }
            numtorank[nums[i]]=rank;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=numtorank[arr[i]];
        }
        return arr;
    }
};