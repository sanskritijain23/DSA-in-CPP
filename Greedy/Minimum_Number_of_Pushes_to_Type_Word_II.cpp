/*
Problem: Minimum Number of Pushes to Type Word II
Platform: LeetCode (#3016)
Topic: Greedy, Frequency Counting, Sorting, Strings

Approach:
- Count the frequency of all 26 characters.
- Sort the frequencies in descending order.
- Assign the 8 most frequent characters a cost of 1 push each.
- Assign the next 8 characters a cost of 2 pushes each.
- Assign the next 8 characters a cost of 3 pushes each, and so on.
- Multiply each character's frequency by its assigned push cost
  and add it to the answer.

Time Complexity: O(n + 26 log 26) = O(n)
Space Complexity: O(26) = O(1)
*/


class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency(26,0);
        for(char& c:word){
            ++frequency[c-'a'];

        }
        sort(frequency.rbegin(),frequency.rend());
        int totalpushes=0;
        for(int i=0;i<26;++i){
            if(frequency[i]==0)    break;
            totalpushes+=(i/8+1)*frequency[i];
        }
        return totalpushes;
    }
};