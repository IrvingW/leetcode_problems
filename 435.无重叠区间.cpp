/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        auto cmp = [](vector<int>& a, vector<int>& b)->bool {
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][0];
        int maxInterval = 0;
        for (auto& interval : intervals) {
            if (interval[0] >= end) {
                end = interval[1];
                maxInterval++;
            }
        }
        return intervals.size() - maxInterval;
    }
};
// @lc code=end

