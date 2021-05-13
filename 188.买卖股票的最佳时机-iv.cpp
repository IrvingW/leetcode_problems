/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (37.42%)
 * Likes:    501
 * Dislikes: 0
 * Total Accepted:    70.9K
 * Total Submissions: 189.1K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 *
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 *
 * 示例 2：
 *
 *
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 * ⁠    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * 0
 * 0
 *
 *
 */
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int days = prices.size();
        // 退化为贪心算法
        if (k * 2 > days) {
            int greedyResult = 0;
            for (int i = 1; i < days; i++) {
                if (prices[i] > prices[i - 1]) {
                    greedyResult += (prices[i] - prices[i - 1]);
                }
            }
        }
        // 普通解法
        vector<vector<int>> hold(days, vector<int>(k + 1));
        vector<vector<int>> rest(days, vector<int>(k + 1));
        hold[0][0] = -prices[0];
        for (int i = 1; i <= k; i++) {
            hold[0][i] = rest[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < days; i++) {
            hold[i][0] = max(hold[i - 1][0], rest[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                hold[i][j] = max(hold[i - 1][j], rest[i - 1][j] - prices[i]);
                rest[i][j] = max(rest[i - 1][j], hold[i - 1][j - 1] + prices[i]);
            }
        }
        int result = 0;
        for (int i = 0; i <= k; i++) {
            result = max(result, rest[days - 1][i]);
        }
        return result;
    }
};
// @lc code=end

