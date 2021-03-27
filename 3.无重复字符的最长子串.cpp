/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int answer = 1;
        map<char, int> charToIndexMap;
        int leftPointer = 0;
        int rightPointer = 0;
        for (int i = 0; i < s.size(); ++i) {
            // right pointer 右移一位
            rightPointer = i;
            char rightNewChar = s[rightPointer];
            if (charToIndexMap.count(rightNewChar) > 0) {
                // 如果right new char出现过
                // 那么更新left pointer 到right new char 上次出现的后一位
                int oldLeftPointer = leftPointer;
                leftPointer = charToIndexMap[rightNewChar] + 1;
                for (int j = oldLeftPointer; j < leftPointer; ++j) {
                    // 清理map
                    charToIndexMap.erase(s[j]);
                }
            }
            // map里加入新的字符
            charToIndexMap[rightNewChar] = rightPointer;
            // 更新
            int newSize = rightPointer - leftPointer + 1;
            answer = (newSize > answer)? newSize : answer;
        }
        return answer;
    }
};
// @lc code=end

