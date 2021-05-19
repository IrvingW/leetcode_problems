/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 *
 * https://leetcode-cn.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (62.78%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    47.4K
 * Total Submissions: 75.5K
 * Testcase Example:  '"00110011"'
 *
 * 给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。
 *
 * 重复出现的子串要计算它们出现的次数。
 *
 *
 *
 * 示例 1 :
 *
 *
 * 输入: "00110011"
 * 输出: 6
 * 解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
 *
 * 请注意，一些重复出现的子串要计算它们出现的次数。
 *
 * 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
 *
 *
 * 示例 2 :
 *
 *
 * 输入: "10101"
 * 输出: 4
 * 解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
 *
 *
 *
 *
 * 提示：
 *
 *
 * s.length 在1到50,000之间。
 * s 只包含“0”或“1”字符。
 *
 *
 */

#include <string>
#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 0;
        vector<int> seq;
        int count = 0;
        char pre = s[0];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == pre) count += 1;
            else {
                seq.push_back(count);
                count = 1;
                pre = s[i];
            }
        }
        seq.push_back(count);
        if (seq.size() < 2) return 0;
        int result = 0;
        for (int i = 1; i < seq.size(); i++) {
            int common = min(seq[i], seq[i - 1]);
            result += common;
        }
        return result;
    }
};
// @lc code=end

