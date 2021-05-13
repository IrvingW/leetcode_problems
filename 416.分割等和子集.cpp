/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.81%)
 * Likes:    778
 * Dislikes: 0
 * Total Accepted:    125.1K
 * Total Submissions: 251K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 转换为sum/2的背包问题
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (auto& num: nums) {
            for (int j = target; j >= num; j--) {
                // dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end

