// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        backtrack(digits, phone, 0, "", result);
        return result;
    }
    
private:
    void backtrack(const string& digits, const unordered_map<char, string>& phone, int index, string current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[index];
        const string& letters = phone.at(digit);
        
        for (char letter : letters) {
            backtrack(digits, phone, index + 1, current + letter, result);
        }
    }
};