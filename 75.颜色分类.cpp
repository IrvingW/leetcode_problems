/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>

using namespace std;

// @lc code=star
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = -1;
        int p1 = 0;
        int p2 = nums.size();
        while(p1 < p2) {
            if (nums[p1] == 0) {
                swap(++p0, p1++, nums);
            } else if (nums[p1] == 2) {
                swap(p1, --p2, nums);
            } else {
                p1++;
            }
        }
    }
private:
    void swap(int index1, int index2, vector<int>& nums) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

};
// @lc code=end



