/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (50.61%)
 * Likes:    532
 * Dislikes: 0
 * Total Accepted:    68.3K
 * Total Submissions: 134.9K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 *
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 *
 * 说明：
 *
 *
 * 字母异位词指字母相同，但排列不同的字符串。
 * 不考虑答案输出的顺序。
 *
 *
 * 示例 1:
 *
 *
 * 输入:
 * s: "cbaebabacd" p: "abc"
 *
 * 输出:
 * [0, 6]
 *
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入:
 * s: "abab" p: "ab"
 *
 * 输出:
 * [0, 1, 2]
 *
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 *
 *
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need;
        unordered_map<char, int> got;
        for (auto& c  : p) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> result;
        while(right < s.size()) {
            char& c = s[right++];
            if (need.count(c) > 0) {
                got[c]++;
                if (got[c] == need[c]) valid++;
            }
            if (right - left > p.size()) {
                char& c = s[left++];
                if (need.count(c)) {
                    if (got[c] == need[c]) valid--;
                    got[c]--;
                }
            }
            if (valid == need.size()) result.push_back(left);
        }
        return result;
    }
};
// @lc code=end

