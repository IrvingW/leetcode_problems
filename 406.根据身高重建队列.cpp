/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() == 0) return people;
        // h decline
        // k increase
        auto cmp = [](vector<int>& a, vector<int>& b) -> bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] > b[0];
            }
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;
        for (auto& p: people) {
            result.insert(result.begin() + p[1], p);
        }
        return result;
    }
};
// @lc code=end

