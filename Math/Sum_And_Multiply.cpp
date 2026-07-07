/*
Problem: Sum And Multiply
Platform: LeetCode
Topic: Math, String

Approach:
- Convert the number into a string.
- Calculate the sum of all digits.
- Construct a new number by ignoring all zero digits.
- Return the product of the new number and the digit sum.

Time Complexity: O(d)
Space Complexity: O(d)
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        string s=to_string(n);
        for(char c:s){
            int d=c-'0';
            sum+=d;
            if(d>0){
                x=x*10+d;
            }
        }
        return x*sum;
    }
};