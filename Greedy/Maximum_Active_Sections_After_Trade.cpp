/*
Problem: Maximum Active Sections After Trade
Platform: LeetCode
Topic: Greedy, Strings

Approach:
- Count the number of active ('1') sections.
- Traverse the string and compute the length of every consecutive inactive ('0') block.
- Store the lengths of all inactive blocks.
- Find the maximum sum of two adjacent inactive blocks.
- Add this maximum gain to the initial count of active sections.

Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int account=count(begin(s),end(s),'1');
        vector<int> inactiveblocks;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0') i++;
                inactiveblocks.push_back(i-start);
            }
            else{
                i++;
            }
        }
        int maxpairsum=0;
        for(int i=1;i<inactiveblocks.size();i++){
            maxpairsum=max(maxpairsum,inactiveblocks[i]+inactiveblocks[i-1]);
        }
        return maxpairsum+account;
    }
};