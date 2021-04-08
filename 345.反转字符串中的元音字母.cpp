/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <string>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        auto inVowels = [](const char& input)-> bool {
            set<char> vowelSet = {'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U'};
            if (vowelSet.count(input) > 0) return true;
            else return false;
        };
        int length = s.size();
        if (length <= 1) return s;

        int left = 0;
        int right = length - 1;
        string result = s;
        while(left < right) {
            if (inVowels(s[left]) && inVowels(s[right])) {
                result[left] = s[right];
                result[right] = s[left];
                left++;
                right--;
            } else if (inVowels(s[left])) {
                right--;
            } else if (inVowels(s[right])) {
                left++;
            } else {
                left++;
                right--;
            }
        }
        return result;
    }
private:
};
// @lc code=end

