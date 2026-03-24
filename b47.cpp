// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// Example 1:
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
class Solution {
public:    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> comb;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, comb, res);
        return res;        
    }

    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& comb, vector<vector<int>>& res) {
        if (comb.size() == nums.size()) {
            res.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            comb.push_back(nums[i]);
            dfs(nums, used, comb, res);
            comb.pop_back();
            used[i] = false;
        }
    }
};