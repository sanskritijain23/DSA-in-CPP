/*
Problem: Minimum Changes To Make Alternating Binary String
Platform: LeetCode (#1758)
Topic: Strings, Greedy

Approach:
- There are only two possible alternating patterns:
    1. Starting with '0' -> "010101..."
    2. Starting with '1' -> "101010..."
- Traverse the string once and count mismatches for both patterns.
- The minimum mismatch count is the required answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    int minOperations(string s) {
        int start0=0;
        int start1=0;

        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0'){
                    start1++;
                }
                else{
                    start0++;
                }
            }
            else{
                if(s[i]=='1'){
                    start1++;
                }
                else{
                    start0++;
                }
            }
        }
        return min(start0,start1);
    }
};