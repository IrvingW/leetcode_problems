/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findK(nums, 0, nums.size() - 1, k);
    }
private:
    int findK(vector<int>& nums, int left, int right, int k) {
        int mid = partition(nums, left, right);
        if (mid - left + 1 > k) {
            return findK(nums, left, mid - 1, k);
        } else if (mid - left + 1 == k) {
            return nums[mid];
        } else {
            return findK(nums, mid + 1, right, k - mid + left - 1);
        }

    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while(low < high) {
            while(low < high && nums[high] <= pivot) high--;
            nums[low] = nums[high];
            while(low < high && nums[low] >= pivot) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
};
// @lc code=end

