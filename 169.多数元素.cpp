/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (65.97%)
 * Likes:    981
 * Dislikes: 0
 * Total Accepted:    312.1K
 * Total Submissions: 473K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：[3,2,3]
 * 输出：3
 *
 * 示例 2：
 *
 *
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 分治法
    // int majorityElement(vector<int>& nums) {
    //     return majority(nums, 0, nums.size() - 1);
    // }
    // 摩尔投票算法
    int majorityElement(vector<int>& nums) {
        int cur = 0;
        int count = 0;
        for (auto& num : nums) {
            if (count == 0) cur = num;
            if (num == cur) count++;
            else count--;
        }
        return cur;
    }
private:
    // int majority(vector<int>& nums, int left, int right) {
    //     if (left == right) return nums[left];
    //     int mid = left + (right - left) / 2;
    //     int m1 = majority(nums, left, mid);
    //     int m2 = majority(nums, mid + 1, right);
    //     if (m1 == m2) return m1;
    //     int c1 = count(nums, m1, left, right);
    //     int c2 = count(nums, m2, left, right);
    //     return c1 > c2 ? m1 : m2;
    // }
    // int count(vector<int>&nums, int num, int left, int right) {
    //     int result = 0;
    //     for (int i = left; i <= right; i++) {
    //         if (nums[i] == num)
    //             result += 1;
    //     }
    //     return result;
    // }
};
// @lc code=end

