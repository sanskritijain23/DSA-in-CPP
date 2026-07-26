/*
Problem: Maximum Product of Two Digits
Platform: LeetCode
Topic: Greedy, Math

Approach:
- Traverse all digits of the number.
- Maintain the two largest digits encountered so far.
- Update the largest and second largest digit while iterating.
- Return the product of the two maximum digits.

Time Complexity: O(log10(n))
Space Complexity: O(1)
*/


class Solution {
public:
    int maxProduct(int n) {
        int first=0,second=0;
        while(n>0){
            int x=n%10;
            if(x>first){
                second=first;
                first=x;
            }
            else if(x>second){
                second=x;
            }
            n/=10;
        }
        return first*second;
    }
};