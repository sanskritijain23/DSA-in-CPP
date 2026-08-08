/*
Problem: Minimum Number of Pushes to Type Word I
Platform: LeetCode (#3014)
Topic: Greedy, Strings, Math

Approach:
- There are 8 available keys.
- The first 8 characters can be assigned with 1 push each.
- The next 8 characters require 2 pushes each.
- The next 8 require 3 pushes each, and so on.
- For the character at index i, required pushes are (i / 8) + 1.
- Add this value for all characters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=i/8+1;
        } 
        return ans;
    }
};