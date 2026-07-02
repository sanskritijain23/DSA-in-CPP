/*
Problem: Number of Substrings Containing All Three Characters
Platform: LeetCode (#1358)
Topic: Sliding Window

Approach:
- Track the last seen index of 'a', 'b', and 'c'.
- For every index, update the last occurrence of the current character.
- Once all three characters have been seen, the minimum last seen index
  determines how many valid substrings end at the current index.
- Add (minimum last seen index + 1) to the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3,-1);
        int cnt=0;
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt=cnt+(1+min({lastseen[0],lastseen[1],lastseen[2]}));
            }
        }
        return cnt;
    }
};
