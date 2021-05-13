/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (50.20%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 46K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
 *
 * 现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
 *
 * 数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,2,2,5,2,3,7]
 * 输出：5
 * 解释：最长的和谐子序列是 [3,2,2,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,4]
 * 输出：2
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,1,1,1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^9
 *
 *
 */

#include <map>
#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counts;
        for (auto& num : nums) {
            counts[num]++;
        }
        int result = 0;
        for (auto& p : counts) {
            if (counts.count(p.first + 1) > 0) {
                result = max(result, p.second + counts[p.first + 1]);
            }
        }
        return result;
    }
};
// @lc code=end