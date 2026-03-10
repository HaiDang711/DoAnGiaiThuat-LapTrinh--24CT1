// Cho một chuỗi đầu vào s và một mẫu p, hãy triển khai việc khớp biểu thức chính quy với hỗ trợ cho '.'và '*'trong đó:
// '.'Khớp với bất kỳ ký tự đơn nào.
// '*'Khớp với không hoặc nhiều hơn một phần tử đứng trước nó.
// Trả về giá trị boolean cho biết liệu kết quả khớp có bao phủ toàn bộ chuỗi đầu vào hay không (không bao phủ một phần).
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};