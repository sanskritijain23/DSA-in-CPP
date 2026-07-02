/*
Problem: Maximum Points You Can Obtain from Cards
Platform: LeetCode (#1423)
Topic: Sliding Window

Approach:
- Start by taking the first k cards from the left.
- Gradually remove one card from the left end and add one card from the right end.
- Track the maximum score obtained after each shift.
- The maximum score among all possible combinations is the answer.

Time Complexity: O(k)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& cardScore, int k) {
         int lsum=0,rsum=0,maxsum=0;
        for(int i=0;i<k;i++){
            lsum=lsum+cardScore[i];
        }
        maxsum=lsum;
        int rindex=cardScore.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-cardScore[i];
            rsum=rsum+cardScore[rindex];
            rindex=rindex-1;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};