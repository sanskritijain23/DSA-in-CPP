/*
Problem: Word Ladder
Platform: LeetCode (#127)
Topic: Graphs, BFS

Approach:
- Store all words from the word list in an unordered_set for O(1) lookup.
- Start BFS from the begin word.
- For each word, change every character from 'a' to 'z' to generate all possible transformations.
- If a transformed word exists in the set, push it into the queue with distance +1 and remove it from the set.
- The first time the target word is reached gives the shortest transformation sequence.

Time Complexity: O(N × L × 26)
Space Complexity: O(N)

where:
N = number of words
L = length of each word
*/


class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==targetWord)    return steps;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};