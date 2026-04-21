// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;
        queue<vector<string>> q;
        q.push({beginWord});
        int minLen = INT_MAX;
        while (!q.empty()) {
            auto path = q.front();
            q.pop();
            if (path.size() > minLen) break;
            string last = path.back();
            if (last == endWord) {
                res.push_back(path);
                minLen = path.size();
                continue;
            }
            for (int i = 0; i < last.size(); i++) {
                string next = last;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    if (dict.count(next) && find(path.begin(), path.end(), next) == path.end()) {
                        auto newPath = path;
                        newPath.push_back(next);
                        q.push(newPath);
                    }
                }
            }
        }
        return res;
    }
};