/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (53.61%)
 * Likes:    770
 * Dislikes: 0
 * Total Accepted:    119.5K
 * Total Submissions: 222.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 *
 *
 * 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9
 *
 *
 */
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto&& num : nums) {
            s.insert(num);
        }
        int result = 0;
        for (auto num : nums) {
            // from left
            if (s.count(num - 1) == 0) {
                int len = 0;
                while (s.count(num) > 0) {
                    len += 1;
                    num += 1;
                }
                result = max(result, len);
            }
        }
        return result;
    }
};
// @lc code=end

