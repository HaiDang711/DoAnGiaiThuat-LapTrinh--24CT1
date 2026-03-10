// Bảy ký hiệu khác nhau đại diện cho các chữ số La Mã với các giá trị sau:

// Biểu tượng	Giá trị
// TÔI	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000
// Chữ số La Mã được hình thành bằng cách ghép các giá trị vị trí thập phân từ cao nhất đến thấp nhất. Việc chuyển đổi giá trị vị trí thập phân thành chữ số La Mã tuân theo các quy tắc sau:

// Nếu giá trị không bắt đầu bằng 4 hoặc 9, hãy chọn ký hiệu của giá trị tối đa có thể trừ đi từ giá trị nhập vào, thêm ký hiệu đó vào kết quả, trừ đi giá trị của nó, và chuyển đổi phần dư thành chữ số La Mã.
// Nếu giá trị bắt đầu bằng 4 hoặc 9, hãy sử dụng  dạng phép  trừ biểu thị một ký hiệu trừ đi ký hiệu kế tiếp, ví dụ: 4 Inhỏ hơn 5 ( ) một đơn vị ( V): IV và 9 Inhỏ hơn 10 ( ) một đơn vị ( X): IX. Chỉ sử dụng các dạng phép trừ sau: 4 ( IV), 9 ( IX), 40 ( XL), 90 ( XC), 400 ( CD) và 900 ( CM).
// Chỉ có lũy thừa của 10 ( I, X, C, M) mới có thể được ghép nối liên tiếp tối đa 3 lần để biểu thị bội số của 10. Bạn không thể ghép 5 ( V), 50 ( L), hoặc 500 ( D) nhiều lần. Nếu bạn cần ghép một ký hiệu 4 lần, hãy sử dụng dạng trừ .
// Cho một số nguyên, hãy chuyển đổi nó thành chữ số La Mã.
class Solution {
public:
    string intToRoman(int num) {
        // Mảng các giá trị từ lớn đến nhỏ
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // Mảng các ký hiệu tương ứng
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }
};