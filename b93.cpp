// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        backtracking(s, 0, 0, path, res);
        return res;
    }

    void backtracking(string s, int startIndex, int pointNum, string& path, vector<string>& res) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                path += s.substr(startIndex);
                res.push_back(path);
                path.erase(path.size() - (s.size() - startIndex));
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path += str + ".";
                backtracking(s, i + 1, pointNum + 1, path, res);
                path.erase(path.size() - (str.size() + 1));
            } else {
                break;
            }
        }
    }

    bool isValid(string s, int left, int right) {
        if (left > right) {
            return false;
        }
        if (s[left] == '0' && left != right) {
            return false;
        }
        int num = 0;
        for (int i = left; i <= right; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
};