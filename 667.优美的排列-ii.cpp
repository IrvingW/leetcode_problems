/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 *
 * https://leetcode-cn.com/problems/beautiful-arrangement-ii/description/
 *
 * algorithms
 * Medium (61.86%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 11.1K
 * Testcase Example:  '3\n1'
 *
 * 给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：
 *
 *
 * 假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|, |a3 -
 * a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
 *
 *
 * 返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, k = 1
 * 输出：[1, 2, 3]
 * 解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, k = 2
 * 输出：[1, 3, 2]
 * 解释：[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
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
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result = gen(k);
        int i = result.size() + 1;
        for (;i <= n; i++) {
            result.push_back(i);
        }
        return result;
    }
private:
    vector<int> gen(int k) {
        int left = 1;
        int right = k + 1;
        vector<int> result;
        while (left < right) {
            result.push_back(left++);
            result.push_back(right--);
        }
        if (left == right) result.push_back(left);
        return result;
    }

};
// @lc code=end

