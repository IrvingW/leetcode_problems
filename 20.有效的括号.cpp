/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.10%)
 * Likes:    2415
 * Dislikes: 0
 * Total Accepted:    639.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 * 输出：false
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "([)]"
 * 输出：false
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "{[]}"
 * 输出：true
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由括号 '()[]{}' 组成
 *
 *
 */
#include <string>
#include <unordered_set>
#include <stack>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        for (auto&& c : s) {
            if (left.count(c) > 0) {
                stack.push(c);
            } else {
                if (stack.empty()) return false;
                char& top = stack.top();
                if (match[c] != top) return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
private:
    unordered_set<char> left = {'(', '{', '['};
    unordered_set<char> right = {')', '}', ']'};
    unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> stack;
};
// @lc code=end

