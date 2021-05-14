/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.43%)
 * Likes:    608
 * Dislikes: 0
 * Total Accepted:    166.3K
 * Total Submissions: 305.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 *
 * 输入为 非空 字符串且只包含数字 1 和 0。
 *
 *
 *
 * 示例 1:
 *
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 *
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 *
 *
 *
 * 提示：
 *
 *
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 *
 *
 */

#include <string>
#include <stack>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int p1 = a.length() - 1;
        int p2 = b.length() - 1;
        stack<int> result;
        stringstream ss;
        int carry = 0;
        while(p1 >= 0 || p2 >= 0 || carry == 1) {
            if (p1 >= 0 && a[p1--] == '1') {
                carry += 1;
            }
            if (p2 >= 0 && b[p2--] == '1') {
                carry += 1;
            }
            result.push(carry % 2);
            carry = carry / 2;
        }
        while(!result.empty()) {
            ss << result.top();
            result.pop();
        }
        return ss.str();
    }
};
// @lc code=end

