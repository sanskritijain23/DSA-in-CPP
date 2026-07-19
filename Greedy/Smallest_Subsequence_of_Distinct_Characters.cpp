/*
Problem: Smallest Subsequence of Distinct Characters
Platform: LeetCode (#1081)
Topic: Greedy, Monotonic Stack, Strings

Approach:
- Store the last occurrence index of every character.
- Traverse the string while maintaining the current answer.
- Skip characters that are already included in the subsequence.
- While the current character is smaller than the last character in the result
  and the last character appears again later, remove it from the result.
- Add the current character and mark it as included.
- The final string is the lexicographically smallest subsequence containing
  every distinct character exactly once.

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    string smallestSubsequence(string s) {
        int n= s.size();
        string result;
        vector<bool> taken(26,false);
        vector<int> lastindex(26);
        for(int i=0;i<n;i++){
            char ch=s[i];
            lastindex[ch-'a']=i;
        }
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(taken[idx]==true)    continue;
            while(result.length()>0 && s[i]<result.back() && lastindex[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[idx]=true;
        }
        return result;
    }
};