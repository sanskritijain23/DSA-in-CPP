/*
Problem: Smallest Palindromic Rearrangement II
Platform: LeetCode
Topic: Strings, Greedy, Combinatorics, Palindrome

Approach:
- Count the frequency of every character.
- A palindrome is completely determined by its left half and
  optional middle character.
- Store half of each character frequency.
- Construct the left half greedily from left to right.
- At every position:
    - Try characters from 'a' to 'z'.
    - Temporarily use that character.
    - Count how many distinct permutations can be formed
      from the remaining characters.
    - If at least k arrangements exist, keep that character.
    - Otherwise skip those arrangements and decrease k.
- Mirror the constructed left half to form the right half.
- Insert the odd-frequency character in the middle when required.

Time Complexity: Depends on permutation-count implementation.
Space Complexity: O(26 + n)
*/


class Solution {
private:
    long long combination(int n, int r, long long limit) {
        r = min(r, n - r);
        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            if (result >= limit) {
                return limit;
            }
        }

        return result;
    }

    long long countPermutations(vector<int>& freq, int remaining, long long limit) {
        long long ways = 1;
        int total = remaining;

        for (int count : freq) {
            if (count == 0) continue;

            long long choose = combination(total, count, limit);

            ways *= choose;

            if (ways >= limit) {
                return limit;
            }

            total -= count;
        }

        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<int> halfFreq(26, 0);
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;

            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
            }
        }

        int halfLength = s.size() / 2;
        string left;

        for (int position = 0; position < halfLength; position++) {
            bool selected = false;

            for (int ch = 0; ch < 26; ch++) {
                if (halfFreq[ch] == 0) continue;

                halfFreq[ch]--;

                int remaining = halfLength - position - 1;

                long long ways = countPermutations(
                    halfFreq,
                    remaining,
                    k
                );

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    selected = true;
                    break;
                }

                k -= ways;
                halfFreq[ch]++;
            }

            if (!selected) {
                return "";
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0') {
            return left + middle + right;
        }

        return left + right;
    }
};