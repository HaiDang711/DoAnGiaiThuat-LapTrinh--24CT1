// Cho một mảng số nguyên numsđược sắp xếp không giảm dần , hãy loại bỏ các phần tử trùng lặp tại chỗ sao cho mỗi phần tử duy nhất chỉ xuất hiện một lần . Thứ tự tương đối của các phần tử phải được giữ nguyên .

// Giả sử số lượng phần tử duy nhất trong  numslà . Sau khi loại bỏ các phần tử trùng lặp, hãy trả về số lượng phần tử duy nhất  .k​​​​​​​k

// Các phần tử đầu tiên  k của mảng  nums phải chứa các số duy nhất được sắp xếp theo thứ tự . Các phần tử còn lại sau chỉ số này  k - 1 có thể bỏ qua.

// Thẩm phán tùy chỉnh:

// Ban giám khảo sẽ kiểm tra giải pháp của bạn với đoạn mã sau:

// int[] nums = [...]; // Mảng đầu vào
// int[] expectedNums = [...]; // Câu trả lời dự kiến ​​với độ dài chính xác

// int k = removeDuplicates(nums); // Gọi hàm triển khai của bạn

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// Nếu tất cả các điều kiện kiểm tra đều được chấp nhận, thì giải pháp của bạn sẽ được chấp nhận .

 

// Ví dụ 1:

// Đầu vào: nums = [1,1,2]
//  Đầu ra: 2, nums = [1,2,_]
//  Giải thích: Hàm của bạn nên trả về k = 2, với hai phần tử đầu tiên của nums lần lượt là 1 và 2.
// Những gì bạn để lại sau chữ k được trả về (do đó chúng được biểu thị bằng dấu gạch dưới) không quan trọng.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;

    }
};