/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        double right = floor(sqrt((double)c));
        double left = 0.0;
        while(left <= right) {
            double sum = left * left + right * right;
            if (sum > c) {
                right--;
            } else if (sum < c) {
                left++;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

