// Hãy viết một hàm để tìm chuỗi tiền tố chung dài nhất trong một mảng các chuỗi.
// Nếu không có tiền tố chung, hãy trả về chuỗi rỗng "".
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = "";
        int min_len = strs[0].length();
        for (const string& s : strs) {
            min_len = min(min_len, (int)s.length());
        }
        for (int i = 0; i < min_len; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c) {
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};