/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.empty()) return true;
        bool modified = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i - 1]) continue;
            if (modified) return false;
            modified = true;
            if (i - 2 >= 0 && nums[i] < nums[i - 2]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i - 1] = nums[i];
            }
        }
        return true;
    }
};
// @lc code=end


