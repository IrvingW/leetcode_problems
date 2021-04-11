/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int length = s.size();
        if (length <= 1) return true;
        int left = 0;
        int right = length - 1;
        while(left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s.substr(left, right - left)) || isPalindrome(s.substr(left + 1, right - left));
            } else  {
                left++;
                right --;
            }
        }
        return true;
    }
private:
    bool isPalindrome(string s) {
        int length = s.size();
        if (length <= 1) return true;
        int left = 0;
        int right = length - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            } else  {
                left++;
                right --;
            }
        }
        return true;
    }
};
// @lc code=end

