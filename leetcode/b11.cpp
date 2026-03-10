// Cho một mảng số nguyên heightcó độ dài n. Có ncác đường thẳng đứng được vẽ sao cho hai điểm cuối của đường thẳng là và .ith(i, 0)(i, height[i])
// Tìm hai đường thẳng cùng với trục x tạo thành một hình trụ, sao cho hình trụ đó chứa được lượng nước nhiều nhất.
// Đổ lại lượng nước tối đa mà bình chứa có thể chứa được .
// Lưu ý rằng bạn không được nghiêng hộp đựng.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            int width = right - left;
            int current_height = min(height[left], height[right]);
            int current_area = width * current_height;
            max_area = max(max_area, current_area);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};