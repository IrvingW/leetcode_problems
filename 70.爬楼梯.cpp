/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (51.59%)
 * Likes:    1639
 * Dislikes: 0
 * Total Accepted:    435.8K
 * Total Submissions: 839.7K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 注意：给定 n 是一个正整数。
 *
 * 示例 1：
 *
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 *
 * 示例 2：
 *
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 *
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n+1);
        int pre1 = 1;
        int pre2 = 2;
        // dp(n) = dp(n - 1) + dp(n - 2) (n > 2)
        for (int i = 3; i <= n; i++) {
            dp[i] = pre1 + pre2;
            pre1 = pre2;
            pre2 = dp[i];
        }
        return dp[n];
    }
};
// @lc code=end

