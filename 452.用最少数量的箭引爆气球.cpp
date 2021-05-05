/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        auto cmp = [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), cmp);

        int end = points[0][1];
        int maxUnOverlap = 1;
        for (auto& interval: points) {
            if (interval[0] > end) {
                maxUnOverlap++;
                end = interval[1];
            }
        }
        return maxUnOverlap;
    }
};
// @lc code=end

