/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.94%)
 * Likes:    1078
 * Dislikes: 0
 * Total Accepted:    131.1K
 * Total Submissions: 319.7K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 *
 *
 *
 * 进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,0]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -2^31
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0 && nums[i] <= size) {
                if (nums[i] != i + 1) {
                    int val = nums[i];
                    int temp = nums[val - 1];
                    if (val == temp)
                        continue;
                    nums[val - 1] = val;
                    nums[i] = temp;
                    i--;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }
};
// @lc code=end

