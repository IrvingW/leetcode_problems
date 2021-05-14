/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (50.13%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 48.5K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 *
 * 示例 1:
 *
 *
 * 输入: 100
 * 输出: "202"
 *
 *
 * 示例 2:
 *
 *
 * 输入: -7
 * 输出: "-10"
 *
 *
 * 注意: 输入范围是 [-1e7, 1e7] 。
 *
 */
#include <string>
#include <sstream>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        stringstream ss;
        stack<int> s;
        if (num < 0) {
            num = -num;
            ss << "-";
        }
        if (num == 0) return "0";
        while(num != 0) {
            s.push(num % 7);
            num /= 7;
        }
        while(!s.empty()) {
            ss << s.top();
            s.pop();
        }
        return ss.str();
    }
};
// @lc code=end

