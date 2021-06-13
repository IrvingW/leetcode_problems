/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (45.81%)
 * Likes:    968
 * Dislikes: 0
 * Total Accepted:    245.4K
 * Total Submissions: 535.7K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * intervals[i].length == 2
 * 0 i i
 *
 *
 */

#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        };
        vector<vector<int>> result;
        int right = INT_MIN / 2;
        int left = right;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto& interval : intervals) {
            if (interval[0] > right) {
                if (left != INT_MIN / 2) {
                    result.emplace_back<vector<int>>({left, right});
                }
                left = interval[0];
                right = interval[1];
            } else {
                right = max(interval[1], right);
            }
        }
        result.emplace_back<vector<int>>({left, right});
        return result;
    }
};
// @lc code=end

