/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.94%)
 * Likes:    1390
 * Dislikes: 0
 * Total Accepted:    331.5K
 * Total Submissions: 425.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 * nums 中的所有整数 互不相同
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 100) continue;
            int num = nums[i];
            nums[i] = 100;
            vector<vector<int>> suffix = permute(nums);
            if (suffix.empty()) result.push_back(vector<int> {num});
            else {
                for (auto&& v : suffix) {
                    v.push_back(num);
                    result.push_back(move(v));
                }
            }
            nums[i] = num;
        }
        return result;
    }
};
// @lc code=end

