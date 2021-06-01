/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (41.46%)
 * Likes:    1168
 * Dislikes: 0
 * Total Accepted:    139.6K
 * Total Submissions: 336.7K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

#include <string>
#include <unordered_map>
#include <limits.h>
#include <math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> got;
        for (auto&& c : t) {
            need[c] += 1;
        }
        int left = 0, right = 0;
        int valid = 0;
        int minLen = INT_MAX;
        string result = "";
        while(right < s.size()) {
            char& c = s[right++];
            if (need.count(c)) {
                got[c]++;
                if (got[c] == need[c]) valid++;
            }
            // right pointer ++ until got all char needs
            if (valid != need.size()) continue;
            while(valid == need.size()) {
                if (right - left < minLen) {
                    minLen = right - left;
                    result = s.substr(left, minLen);
                }
                char& c = s[left++];
                if (need.count(c)) {
                    if (got[c] == need[c]) valid--;
                    got[c]--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

