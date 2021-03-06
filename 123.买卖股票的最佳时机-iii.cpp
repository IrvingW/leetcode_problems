/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (52.08%)
 * Likes:    765
 * Dislikes: 0
 * Total Accepted:    107K
 * Total Submissions: 205.2K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 *
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：prices = [3,3,5,0,0,3,1,4]
 * 输出：6
 * 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 *
 * 示例 2：
 *
 *
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。  
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 *
 *
 * 示例 3：
 *
 *
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
 *
 * 示例 4：
 *
 *
 * 输入：prices = [1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
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
        // 持有股票
        vector<vector<int>> hold(days, vector<int>(3, 0));
        // 空仓
        vector<vector<int>> rest(days, vector<int>(3, 0));

        // 状态转移方程
        // hold[i][k] = max(hold[i - 1][k], rest[i - 1][k - 1] - prices[i])
        // rest[i][k] = max(rest[i - 1][k], hold[i - 1][k] + prices[i])
        hold[0][1] = -prices[0];
        rest[0][1] = INT_MIN;
        for (int i = 1; i < days; i++) {
            hold[i][0] = INT_MIN;
            for (int k = 1; k < 3; k++) {
                if (rest[i - 1][k - 1] == INT_MIN) {
                    hold[i][k] = hold[i - 1][k];
                } else {
                    hold[i][k] = max(hold[i - 1][k], rest[i - 1][k - 1] - prices[i]);
                }
                rest[i][k] = max(rest[i - 1][k], hold[i - 1][k] + prices[i]);
                if (i < k) {
                    hold[i][k] = INT_MIN;
                }
                if ((i + 1 ) < k * 2) {
                    rest[i][k] = INT_MIN;
                }
            }
        }

        return max(rest[days - 1][2], max(rest[days - 1][1], 0));
    }
};
// @lc code=end


