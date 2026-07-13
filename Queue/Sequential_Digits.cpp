/*
Problem: Sequential Digits
Platform: LeetCode (#1291)
Topic: Queue, BFS

Approach:
- Initialize a queue with single-digit numbers (1 to 8).
- Generate the next sequential number by appending the next digit.
- If the generated number lies within the given range, add it to the result.
- Continue until all possible sequential numbers are generated.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i=1;i<=8;i++){
            que.push(i);
        }
        vector<int> result;
        while(!que.empty()){
            int temp=que.front();
            que.pop();
            if(temp>=low && temp<=high){
                result.push_back(temp);
            }
            int last_digit=temp%10;
            if(last_digit+1<=9){
                que.push(temp*10+(last_digit+1));
            }
               
        }
        return result;
    }
};