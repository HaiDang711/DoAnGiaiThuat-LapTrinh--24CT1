// Chuỗi ký tự "PAYPALISHIRING"được viết theo kiểu zigzag trên một số hàng nhất định như thế này: (bạn có thể muốn hiển thị mẫu này bằng một phông chữ cố định để dễ đọc hơn)

// PAHN
// APLSIIG
// YIR
// Sau đó đọc từng dòng một:"PAHNAPLSIIGYIR"

// Hãy viết đoạn mã nhận vào một chuỗi và thực hiện phép chuyển đổi này dựa trên số lượng hàng:

// chuyển đổi chuỗi (chuỗi s, số nguyên numRows);
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};