/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int length = s.size();
        int maxLen = 0;
        string result;
        // 含义: 字符串从i到j的sub string是否回文
        vector< vector<bool> > isPalindrome(length, vector<bool>(length, false));
        // 对角线，也就是单个字符，设置为true
        for (int i = 0; i < length; i++) {
            isPalindrome[i][i] = true;
        }
        // DP的递推公式
        // if s[i] == s[j] && isPalindrome[i + 1][j - 1]:
        //    isPalindrome[i][j] = true;
        int left(0), right(0);
        for (int j = 1; j < length; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] == s[j]){
                    if (i + 1 == j) {
                        isPalindrome[i][j] = true;
                    } else if(isPalindrome[i+1][j-1] == true) {
                        isPalindrome[i][j] = true;
                    }
                    // update result
                    if (isPalindrome[i][j] == true && ((j - i + 1) > maxLen)) {
                        left = i;
                        right = j;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

// int main(int argc, char const *argv[])
// {
//     Solution solution;
//     solution.longestPalindrome("aacabdkacaa");
//     return 0;
// }
