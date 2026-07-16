/*
Problem: Word Ladder II
Platform: LeetCode (#126)
Topic: Graphs, BFS, DFS, Backtracking

Approach:
- Use level-by-level BFS to build the shortest transformation graph.
- For each transformed word, store all possible parent words that reach it in the shortest path.
- Stop BFS once the end word is found at the current level.
- Perform DFS (backtracking) from the end word to the begin word using the parent map.
- Reverse each constructed path before adding it to the final answer.

Time Complexity: O(N × L × 26 + P)
Space Complexity: O(N × L)

where:
N = number of words
L = length of each word
P = total size of all shortest paths generated
*/


class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &par : parents[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_set<string> currLevel;
        currLevel.insert(beginWord);

        while (!currLevel.empty()) {
            for (auto &w : currLevel)
                dict.erase(w);

            unordered_set<string> nextLevel;

            for (auto &word : currLevel) {

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char orig = temp[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        temp[i] = ch;

                        if (!dict.count(temp))
                            continue;

                        nextLevel.insert(temp);
                        parents[temp].push_back(word);
                    }

                    temp[i] = orig;
                }
            }

            if (nextLevel.count(endWord))
                break;

            currLevel = nextLevel;
        }

        if (!parents.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};