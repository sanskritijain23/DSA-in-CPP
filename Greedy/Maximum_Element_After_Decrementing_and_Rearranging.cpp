/*
Problem: Maximum Element After Decrementing and Rearranging
Platform: LeetCode (#1846)
Topic: Greedy, Sorting

Approach:
- Sort the array in non-decreasing order.
- Set the first element to 1.
- Traverse the array and ensure that the difference between adjacent elements is at most 1.
- If the current element is too large, reduce it to (previous element + 1).
- The last element represents the maximum possible value after rearranging.

Time Complexity: O(n log n)
Space Complexity: O(1)      // Ignoring the space used by sorting
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int maxel=-1;
        for(int i=0;i<n;i++){
            if(i==0){
                arr[0]=1;
            }
            else if(abs(arr[i]-arr[i-1])>1){
                arr[i]=arr[i-1]+1;
            }
            maxel=max(maxel,arr[i]);
        }
        return maxel;
    }
};