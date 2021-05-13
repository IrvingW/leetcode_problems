/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (49.38%)
 * Likes:    1600
 * Dislikes: 0
 * Total Accepted:    264.2K
 * Total Submissions: 534.6K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^4
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你可以设计时间复杂度为 O(n^2) 的解决方案吗？
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 *
 *
 */

#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tail[i] = 长度为i+1的递增自序列的最大值
        // if nums[k] > tail.back() then tail.push_back(nums[k])
        // 相当于最长的递增自序列长度+1
        // if tail[i - 1]  < nums[k] <= tail[i] then
        // tail[i] = nums[k]
        // 最后
        // result = tail.size()
        if (nums.empty()) return 0;
        vector<int> tail;
        tail.push_back(nums[0]);
        for (auto& num : nums) {
            if (num > tail.back()) {
                tail.push_back(num);
            } else if (num == tail.back()) {
            } else {
                int index = binarySearch(tail, num);
                tail[index] = num;
            }
        }
        return tail.size();
    }

private:
    int binarySearch(vector<int>& tail, int key) {
        // if tail[i - 1]  < nums[k] <= tail[i]
        // return i
        int size = tail.size();
        int low = 0;
        int high = size - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (tail[mid] == key) {
                return mid;
            } else if (tail[mid] > key) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end

