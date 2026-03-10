//Cho một chuỗi s, hãy trả về chuỗi dài nhất. đối xứng chuỗi conTRONG s.
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1;

        for (int i = 0; i < s.length(); i++) {
            // Kiểm tra chuỗi con có độ dài lẻ
            expandAroundCenter(s, i, i, start, maxLength);
            // Kiểm tra chuỗi con có độ dài chẵn
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }
private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > maxLength) {
            maxLength = right - left - 1;
            start = left + 1;
        }
    }
};