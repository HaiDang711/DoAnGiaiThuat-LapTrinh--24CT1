// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.
class Solution {
public:    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result(2, -1);

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result[0] = mid;
                result[1] = mid;

                // Expand to the left
                while (result[0] > 0 && nums[result[0] - 1] == target) {
                    result[0]--;
                }

                // Expand to the right
                while (result[1] < nums.size() - 1 && nums[result[1] + 1] == target) {
                    result[1]++;
                }

                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};