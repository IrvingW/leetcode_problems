/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.72%)
 * Likes:    954
 * Dislikes: 0
 * Total Accepted:    121K
 * Total Submissions: 270.5K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 *
 * 示例 1 :
 *
 *
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 *
 *
 * 说明 :
 *
 *
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 *
 *
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        if (nums.empty()) return 0;
        int size = nums.size();
        vector<int> preSum(size + 1, 0);
        unordered_map<int, int> preSumFreq;
        preSumFreq.emplace(0, 1);
        int result = 0;
        for (int i = 1; i < size + 1; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            int need = preSum[i] - k;
            if (preSumFreq.find(need) != preSumFreq.end()) result += preSumFreq[need];
            preSumFreq[preSum[i]] ++;
        }
        return result;
    }
};
// @lc code=end

