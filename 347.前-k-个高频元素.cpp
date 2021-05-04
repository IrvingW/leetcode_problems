/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

using namespace std;

#include <vector>
#include <unordered_map>


// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count for frequency
        unordered_map<int, int> frequencyMap;
        for (auto& num : nums) {
            if (frequencyMap.count(num) == 0) {
                frequencyMap[num] = 0;
            }
            frequencyMap[num] += 1;
        }
        // put into frequency bucket
        vector<int> buckets[nums.size() + 1];
        for (auto p : frequencyMap) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> result;
        // count for topk
        for (int i = nums.size(); i >= 0 && result.size() < k; i--) {
            for (int j = 0; j < buckets[i].size() && result.size() < k; j++) {
                result.push_back(buckets[i][j]);
            }
        }
        return result;
    }
};
// @lc code=end
