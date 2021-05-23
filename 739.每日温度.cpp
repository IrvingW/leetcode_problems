/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.02%)
 * Likes:    759
 * Dislikes: 0
 * Total Accepted:    164.9K
 * Total Submissions: 246.1K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
 * 来代替。
 *
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 *
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 *
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        if (temperatures.empty()) return result;
        int size = temperatures.size();
        result.assign(size, 0);
        stack<int> indexStack;
        for (int i = 0; i < size; i++) {
            while(!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                int& top = indexStack.top();
                result[top] = i - top;
                indexStack.pop();
            }
            indexStack.push(i);
        }
        return result;
    }
};
// @lc code=end

