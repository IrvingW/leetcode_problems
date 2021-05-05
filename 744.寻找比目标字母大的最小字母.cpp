/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) {
            return letters[0];
        }
        int low = 0;
        int high = letters.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target) {
                high = mid - 1;
            } else if (letters[mid] <= target) {
                low = mid + 1;
            }
        }
        return letters[low];
    }
};
// @lc code=end

