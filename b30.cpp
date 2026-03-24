// You are given a string s and an array of strings words. All the strings of words are of the same length.

// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int word_len = words[0].size();
        int total_len = word_len * words.size();
        if (s.size() < total_len) return result;
        
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }
        
        for (int i = 0; i < word_len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            
            for (int j = i; j <= (int)s.size() - word_len; j += word_len) {
                string word = s.substr(j, word_len);
                
                if (word_count.find(word) != word_count.end()) {
                    seen[word]++;
                    count++;
                    
                    while (seen[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }
                    
                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        
        return result;

    }
};