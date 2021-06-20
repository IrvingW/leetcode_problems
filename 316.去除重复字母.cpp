/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (47.62%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    58.9K
 * Total Submissions: 123.7K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 *
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "bcabc"
 * 输出："abc"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 由小写英文字母组成
 *
 *
 */

#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(256, 0);
        vector<bool> inStack(256, false);
        for (auto&& c : s) freq[(int)c]++;
        stack<char> stk;
        for (auto&& c : s) {
            freq[c]--;
            if (inStack[c]) continue;
            while(!stk.empty() && c < stk.top() && freq[stk.top()] > 0) {
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true;
        }
        stringstream ss;
        while(!stk.empty()) {
            ss << stk.top();
            stk.pop();
        }
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

