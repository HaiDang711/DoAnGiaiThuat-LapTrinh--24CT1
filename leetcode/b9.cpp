//Cho một số nguyên x, trả về giá trị truenếu xlà một số nguyênxuôi ngược đều giống nhauvà falsengược lại .
class Solution {
public:
    bool isPalindrome(int x) {
        // Số âm không thể là số palindrome
        if (x < 0) return false;
        // Số 0 là palindrome
        if (x == 0) return true;

        int original = x;
        long long reversed = 0;
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return original == reversed;
    }
};