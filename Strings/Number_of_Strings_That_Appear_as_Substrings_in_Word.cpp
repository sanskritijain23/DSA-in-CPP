/*
Problem: Number of Strings That Appear as Substrings in Word
Platform: LeetCode (#1967)
Topic: Strings

Approach:
- Iterate through each pattern.
- Use the built-in string find() function to check whether the pattern exists as a substring of the given word.
- Count all matching patterns.

Time Complexity: O(n × m)
Space Complexity: O(1)
*/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(auto &p:patterns){
            if(word.find(p)!=string::npos){
                count++;
            }
        }
        return count;
    }
};