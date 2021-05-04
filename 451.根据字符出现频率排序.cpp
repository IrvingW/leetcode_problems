/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

using namespace std;

#include <string>
#include <unordered_map>
#include <vecotr>

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) return "";
        unordered_map<char, int> frequencyMap;
        for (auto& c : s) {
            frequencyMap[c] += 1;
        }
        int len = s.length();
        vector<char> buckets[len + 1];
        for (auto& p : frequencyMap) {
            buckets[p.second].push_back(p.first);
        }
        string result;
        for (int i = len; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                for (int k = 0; k < i; k++) {
                    result += buckets[i][j];
                }
            }
        }
        return result;
    }
};
// @lc code=end

