/*
Problem: Lexicographically Smallest Palindrome
Platform: LeetCode
Topic: Strings, Sorting, Palindrome

Approach:
- Divide the string into two halves.
- Sort only the first half in ascending order.
- Copy the sorted first-half characters to corresponding positions
  in the second half to preserve the palindrome property.
- For an odd-length string, leave the middle character unchanged.

Time Complexity: O(n log n)
Space Complexity: O(log n)
*/


class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int part=n/2;
        sort(s.begin(),s.begin()+part);
        for(int i=0;i<part;i++){
            s[n-1-i]=s[i];
        }
        return s;
    }
};