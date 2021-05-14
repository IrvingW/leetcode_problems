/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (59.99%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 19K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。
 *
 * 例如:
 *
 *
 * 输入:
 * [1,2,3]
 *
 * 输出:
 * 2
 *
 * 说明：
 * 只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）：
 *
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 */

#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0;
        int median = findK(nums, nums.size() / 2);
        for (auto& num : nums) {
            result += abs(num - median);
        }
        return result;
    }
private:
    int findK(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high) {
            int mid = partition(nums, low, high);
            if (mid == k) {
                return nums[mid];
            }
            if (mid > k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nums[low];
    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot  = nums[low];
        while(low < high) {
            if (low < high && nums[high] >= pivot) high--;
            nums[low] = nums[high];
            if (low < high && nums[low] <= pivot) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
};
// @lc code=end

