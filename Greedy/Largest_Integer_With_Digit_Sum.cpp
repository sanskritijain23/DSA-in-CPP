/*
Problem: Largest Integer With Digit Sum
Platform: LeetCode
Topic: Greedy, Math, Digits

Approach:
- Generate all n-digit numbers.
- Calculate the digit sum of each number.
- If the digit sum matches the required sum, update the maximum value.

Time Complexity: O(9^n * n)
Space Complexity: O(n)
*/



class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0){
            return 0;
        }
        int digit=0;
        int start=pow(10,n-1);
        int end=pow(10,n);
        for(int i=start;i<end;i++){
            int sum=0;
            string st=to_string(i);
            for(int j=0;j<n;j++){
                sum=sum+(st[j]-'0');
            }
            if(sum==s){
                digit=max(digit,i);
            }
        }
        if(digit){
            return digit;
        }
        return -1;
    }
};