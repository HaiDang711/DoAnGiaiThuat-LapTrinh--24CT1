// Chữ số La Mã được biểu diễn bằng bảy ký hiệu khác nhau:  I, V, X, L, C, Dvà M.

//        Giá trị ký hiệu
// Tôi 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000
// Ví dụ,  2được viết bằng II chữ số La Mã, chỉ đơn giản là hai số một cộng lại với nhau. 12được viết là  XII, đơn giản là X + II. Số 27được viết là XXVII, tức là XX + V + II.

// Chữ số La Mã thường được viết từ lớn đến nhỏ, từ trái sang phải. Tuy nhiên, chữ số của số bốn không phải là IIII. Thay vào đó, số bốn được viết là IV. Vì số một đứng trước số năm nên ta trừ đi số năm, được kết quả là bốn. Nguyên tắc tương tự áp dụng cho số chín, được viết là IX. Có sáu trường hợp sử dụng phép trừ:

// Icó thể được đặt trước V(5) và X(10) để tạo thành 4 và 9. 
// Xcó thể đặt trước L(50) và C(100) để tạo thành 40 và 90. 
// Ccó thể đặt trước D(500) và M(1000) để tạo thành 400 và 900.
// Cho một chữ số La Mã, hãy chuyển đổi nó thành số nguyên.
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        int prev = 0;
        
        for (int i = s.length() - 1; i >= 0; --i) {
            int current = roman[s[i]];
            if (current < prev) {
                result -= current;
            } else {
                result += current;
            }
            prev = current;
        }
        
        return result;
    }
};