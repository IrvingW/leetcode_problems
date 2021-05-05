/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // greedy
        int kid_index = 0;
        for (int i = 0; i < s.size() && kid_index < g.size(); i++) {
            if (s[i] >= g[kid_index]) {
                // give it to him
                kid_index++;
            }
        }
        return kid_index;
    }
};
// @lc code=end

