/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int need = target - current;
            if (record.count(need) > 0) {
                result.push_back(i);
                result.push_back(record[need]);
            } else {
                record[current] = i;
            }
        }
        return result;
    }
};
// @lc code=end

