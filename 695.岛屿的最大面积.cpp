/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == 1) {
                    pair<int, int> p(row, col);
                    int size = area(grid, p);
                    maxArea = maxArea > size ? maxArea : size;
                }
            }
        }
        return maxArea;
    }
private:
    int area(vector<vector<int>>& grid, pair<int, int>& p) {
        stack<pair<int, int>> s;
        s.push(p);
        int result = 0;
        while(!s.empty()) {
            auto& p = s.top();
            result++;
            grid[p.first][p.second] = 0;
            if (p.first + 1 < grid.size() && grid[p.first + 1][p.second] == 1) {
                s.push(make_pair(p.first + 1, p.second));
            }
            if (p.first - 1 > 0 && grid[p.first - 1][p.second] == 1) {
                s.push(make_pair(p.first - 1, p.second));
            }
            if (p.second + 1 < grid[0].size() && grid[p.first][p.second + 1] == 1) {
                s.push(make_pair(p.first, p.second + 1));
            }
            if (p.second - 1 > 0 && grid[p.first][p.second - 1] == 1) {
                s.push(make_pair(p.first, p.second - 1));
            }
            s.pop();
        }
        return result;
    }
};
// @lc code=end

