// Cho một số nguyên 32 bit có dấu x, hãy trả xvề giá trị đã đảo ngược các chữ số . Nếu việc đảo ngược xkhiến giá trị nằm ngoài phạm vi số nguyên 32 bit có dấu , thì hãy trả về giá trị rỗng .[-231, 231 - 1]0
// Giả sử môi trường không cho phép bạn lưu trữ các số nguyên 64 bit (có dấu hoặc không dấu).
class Solution {
public:    int reverse(int x) {
        int reversed = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Kiểm tra tràn số nguyên
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;

            reversed = reversed * 10 + pop;
        }
        return reversed;
    }
};