/*
Problem: Predict the Winner
Platform: LeetCode (#486)
Topic: Dynamic Programming, Recursion, Game Theory, Minimax

Approach:
- At every turn, the player can take either the leftmost or rightmost element.
- Since both players play optimally, after the current player chooses an end,
  the opponent will force the minimum possible future score for the current player.
- Recursively calculate:
    1. Score obtained by taking nums[i].
    2. Score obtained by taking nums[j].
- Take the maximum of these two choices.
- Calculate Player 2's score using totalSum - Player1Score.
- Player 1 wins if their score is greater than or equal to Player 2's score.

Time Complexity: Exponential without memoization
Space Complexity: O(n) recursion stack
*/


class Solution {
public:
    int solve(int i, int j, vector<int> & nums){
        if(i>j)    return 0;
        if(i==j){
            return nums[i];
        }
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total_score=accumulate(begin(nums),end(nums),0);
        int p1_score=solve(0,n-1,nums);
        int p2_score=total_score-p1_score;
        return p1_score>=p2_score;
    }
};