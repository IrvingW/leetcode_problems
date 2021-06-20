/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.18%)
 * Likes:    1837
 * Dislikes: 0
 * Total Accepted:    289.2K
 * Total Submissions: 374.7K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：["()"]
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

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<char> prefix;
        backtrace(n, n, prefix, result);
        return result;
    }
private:
    void backtrace(int leftBrace, int rightBrace, vector<char>& prefix, vector<string>& result) {
        if (leftBrace < 0 || rightBrace < 0) return;
        if (leftBrace > rightBrace) return;
        if (leftBrace == 0 && rightBrace == 0) {
            string s;
            for (auto&& c : prefix) s += c;
            result.push_back(s);
        }
        prefix.push_back('(');
        backtrace(leftBrace - 1, rightBrace, prefix, result);
        prefix.pop_back();

        prefix.push_back(')');
        backtrace(leftBrace, rightBrace - 1, prefix, result);
        prefix.pop_back();
    }
};
// @lc code=end

