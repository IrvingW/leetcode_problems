/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums.back()) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};
// @lc code=end

