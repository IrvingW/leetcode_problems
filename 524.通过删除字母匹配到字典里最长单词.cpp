/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string answer = "";
        if (dictionary.size() == 0 || s.empty())
            return "";
        for (int i = 0; i < dictionary.size(); i++) {
            auto& target = dictionary[i];
            if (check(s, target)) {
                if (target.size() > answer.size()) {
                    answer = target;
                }
                if (target.size() == answer.size()) {
                    if (answer.empty() || target < answer)
                        answer = target;
                }
            }
        }
        return answer;
    }

private:
    bool check(string& input, string& target) {
        if (input == target)
            return true;
        int targetLength = target.size();
        int targetIndex = 0;
        for (int i = 0; i < input.size(); i++) {
            if (target[targetIndex] == input[i]) {
                targetIndex++;
            }
            if (targetIndex == targetLength)
                return true;
        }
        return false;
    }
};
// @lc code=end