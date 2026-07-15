/*
Problem: GCD of Odd and Even Sums
Platform: LeetCode Weekly Contest
Topic: Math, Number Theory

Approach:
- Sum of the first n odd numbers = n².
- Sum of the first n even numbers = n(n + 1).
- Therefore:
      gcd(n², n(n + 1))
    = n × gcd(n, n + 1)
    = n
  since consecutive integers are always coprime.

Time Complexity: O(1)
Space Complexity: O(1)
*/


class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};