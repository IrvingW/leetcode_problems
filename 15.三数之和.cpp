/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (32.33%)
 * Likes:    3414
 * Dislikes: 0
 * Total Accepted:    533.8K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^5
 *
 *
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if (size < 3) return result;
        sort(nums.begin(), nums.end());
        int pre = nums[0] + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pre) continue;
            pre = nums[i];
            vector<vector<int>> twoSumResult = twoSum(nums, i + 1, 0 - nums[i]);
            for (auto&& sum : twoSumResult) {
                sum.push_back(nums[i]);
                result.push_back(move(sum));
            }
        }
        return result;
    }

private:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> result;
        int left = start;
        int right = nums.size() - 1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                result.emplace_back<vector<int>>({nums[left++], nums[right--]});
                while(left < right && nums[left] == nums[left - 1]) left++;
                while(left < right && nums[right] == nums[right + 1]) right--;
            }
        }
        return result;
    }
};
// @lc code=end

