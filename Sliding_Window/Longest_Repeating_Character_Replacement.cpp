/*
Problem: Longest Repeating Character Replacement
Platform: LeetCode (#424)
Topic: Sliding Window

Approach:
- Use a sliding window with a frequency array.
- Track the maximum frequency character in the current window.
- If (window size - max frequency) > k, shrink the window.
- Update the maximum valid window length.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxf=0;
        int hash[26]={0};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            while((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++)    maxf=max(maxf,hash[i]);
                l=l+1;
            }
            if((r-l+1)-maxf<=k)
                maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};