/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (60.08%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    106.5K
 * Total Submissions: 177.1K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续 1 的个数。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：[1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 *
 *
 *
 *
 * 提示：
 *
 *
 * 输入的数组只包含 0 和 1 。
 * 输入数组的长度是正整数，且不超过 10,000。
 *
 *
 */

#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int pre = 0;
        for (auto& num : nums) {
            if (num == 1) {
                pre += 1;
                result = max(result, pre);
            } else {
                pre = 0;
            }
        }
        return result;
    }
};
// @lc code=end

