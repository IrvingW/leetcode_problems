/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        recursive("", digits, result);
        return result;
    }
private:
    void recursive(const string& prefix, const string& digits, vector<string>& result) {
        if (prefix.length() == digits.length()) {
            result.push_back(prefix);
        }
        int digit = atoi(digits.substr(prefix.size(), 1).c_str());
        auto& letters = dict[digit];
        for (auto& letter : letters) {
            recursive(prefix + letter, digits, result);
        }
    }
    vector<vector<string>> dict = {
        {}, {},{
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}
    };
};
// @lc code=end

