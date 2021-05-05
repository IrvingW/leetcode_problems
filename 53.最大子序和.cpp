/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = nums[0];
        int preMaxSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] + preMaxSum > nums[i]) {
                preMaxSum += nums[i];
            } else {
                preMaxSum = nums[i];
            }
            result = max(preMaxSum, result);
        }
        return result;
    }
};
// @lc code=end

