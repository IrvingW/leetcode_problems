/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.76%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    63.1K
 * Total Submissions: 144.3K
 * Testcase Example:  '16'
 *
 * 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
 *
 * 进阶：不要 使用任何内置的库函数，如  sqrt 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num = 16
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = 14
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int high = num / 2;
        int low = 1;
        while (low <= high) {
            float mid = low + (high - low) / 2;
            float r = num / mid;
            if (r == mid) return true;
            if (r > mid) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
// @lc code=end

