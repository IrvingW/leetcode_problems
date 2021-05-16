/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0) {
            return -1;
        }
        int pathLen = 0;
        queue<vector<int, int>> level;
        vector<int, int> origin = {0, 0};
        level.push(origin);
        while(!level.empty()) {
            pathLen++;
            int size = level.size();
            for (int i = 0; i < size; i++) {
                const auto& cur = level.front();
                if (cur[0] < 0 || cur[0] >= n || cur[1] < 0 || cur[1] >= m) {
                    // out of range
                    continue;
                }
                if (grid[cur[0], cur[1]] == 1) {
                    continue;
                }
                if (cur[0] == n - 1 && cur[1] == m -1) {
                    return pathLen;
                }
                for (auto& move: moves) {
                    vector<int, int> next = {cur[0] + move[0], cur[1] + move[1]};
                    level.push(next);
                }

                level.pop();
            }
        }
        return -1;
    }
private:
    vector<vector<int>> moves = {
        {1, 0}, {1, 1}, {1, -1},
        {0, 1}, {0, -1},
        {-1, -1}, {-1, 0}, {-1, 1}
    };
};
// @lc code=end

