// Hãy triển khai myAtoi(string s)hàm chuyển đổi chuỗi ký tự thành số nguyên có dấu 32 bit.
// Thuật toán myAtoi(string s)được thực hiện như sau:
// Khoảng trắng : Bỏ qua bất kỳ khoảng trắng nào ở đầu ( " ").
// Tính chất dấu : Xác định dấu bằng cách kiểm tra xem ký tự tiếp theo có phải là '-'hoặc hay không '+', giả định là dương nếu cả hai đều không xuất hiện.
// Chuyển đổi : Đọc số nguyên bằng cách bỏ qua các số 0 đứng đầu cho đến khi gặp ký tự không phải chữ số hoặc đến cuối chuỗi. Nếu không đọc được chữ số nào, thì kết quả là 0.
// Làm tròn : Nếu số nguyên nằm ngoài phạm vi số nguyên có dấu 32 bit , thì hãy làm tròn số nguyên đó để vẫn nằm trong phạm vi. Cụ thể, các số nguyên nhỏ hơn nên được làm tròn thành , và các số nguyên lớn hơn nên được làm tròn thành .[-231, 231 - 1]-231-231231 - 1231 - 1
// Trả về số nguyên đó làm kết quả cuối cùng.
class Solution {
public:    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++; // Bỏ qua khoảng trắng

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};