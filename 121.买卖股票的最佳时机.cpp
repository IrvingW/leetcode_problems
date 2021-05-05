/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min = prices[0];
        int max = 0;
        for (auto& price : prices) {
            if (price < min) min = price;
            else max = max > price - min ? max : price - min;
        }
        return max;
    }
};
// @lc code=end

