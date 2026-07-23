/*
Problem: Rearrange String
Platform: LeetCode
Topic: Sorting, Strings

Approach:
- Compare the two given characters x and y.
- If x is smaller than y, sort the string in descending order.
- Otherwise, sort the string in ascending order.
- Return the rearranged string.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if(x<y){
            sort(s.begin(),s.end(),greater<char>());
        }
        else{
            sort(s.begin(),s.end());
        }
        return s;
    }
};