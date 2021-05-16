/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.empty()) return result;
        recursive(s, "", 0, 0, result);
        return result;
    }
private:
    void recursive(const string& s, const string& prefix, int index, int depth, vector<string>& results) {
        if (index == s.length() && depth == 4) {
            results.push_back(prefix.substr(0, prefix.length() - 1));
        }
        for (int i = 1; i <= 3 && index + i - 1 < s.length(); i++) {
            int digit = atoi(s.substr(index, i).c_str());
            if (digit == 0) {
                recursive(s, prefix + "0.", index+1, depth+1, results);
                break;
            }
            if (digit > 255) {
                break;
            }
            recursive(s, prefix + s.substr(index, i) + ".", index + i, depth+1, results);
        }
    }
};
// @lc code=end

