/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (58.73%)
 * Likes:    769
 * Dislikes: 0
 * Total Accepted:    88.6K
 * Total Submissions: 150.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 *
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *
 *
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 *
 *
 * 示例:
 *
 * 输入: [1,2,3,0,2]
 * 输出: 3
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 *
 */

#include <vector>
#include <limits.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int days = prices.size();
        vector<int> hold(days);
        vector<int> sold(days);
        hold[0] = -prices[0];
        sold[0] = 0;
        for (int i = 1; i < days; i++) {
            if (i == 1) {
                hold[1] = max(-prices[0], -prices[1]);
            } else {
                hold[i] = max(hold[i - 1], sold[i - 2] - prices[i]);
            }
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i]);
        }
        return sold[days - 1];
    }
};
// @lc code=end
