/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (50.01%)
 * Likes:    974
 * Dislikes: 0
 * Total Accepted:    143.1K
 * Total Submissions: 286K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 *
 * 说明：
 *
 *
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 *
 *
 * 示例 1：
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 *
 *
 * 示例 2：
 *
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 *
 *
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return false;
        int size = s.length();
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        for (int i = 1; i <= size; i++) {
            for (auto& word : wordDict) {
                int len = word.length();
                if (i - len >= 0 && s.substr(i - len, len) == word) {
                    dp[i] = dp[i - len] || dp[i];
                }
            }
        }
        return dp[size];
    }
};
// @lc code=end

