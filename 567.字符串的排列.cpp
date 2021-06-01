/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (42.24%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    86.3K
 * Total Submissions: 204K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 *
 * 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 *
 *
 * 示例 2：
 *
 *
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 *
 *
 *
 *
 * 提示：
 *
 *
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 *
 *
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> frequencyNeed;
        unordered_map<char, int> frequencyGot;
        int left = 0;
        int right = 0;
        int valid = 0;
        for (auto&& c : s1) {
            frequencyNeed[c]++;
        }
        while(right < s2.size()) {
            char& c = s2[right++];
            if (frequencyNeed.count(c) > 0) {
                frequencyGot[c]++;
                if (frequencyGot[c] == frequencyNeed[c]) valid++;
            }
            if (right - left > s1.size()) {
                char& c = s2[left++];
                if (frequencyNeed.count(c) > 0) {
                    if (frequencyGot[c] == frequencyNeed[c]) valid--;
                    frequencyGot[c]--;
                }
            }
            if (valid == frequencyNeed.size()) return true;
        }
        return false;
    }
};
// @lc code=end

