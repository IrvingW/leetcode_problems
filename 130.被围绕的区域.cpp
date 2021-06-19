/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (43.49%)
 * Likes:    554
 * Dislikes: 0
 * Total Accepted:    107.5K
 * Total Submissions: 247K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X'
 * 填充。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n == board[i].length
 * 1
 * board[i][j] 为 'X' 或 'O'
 *
 *
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size();
        n = board[0].size();
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, make_pair(0, j), '#');
            if (board[m - 1][j] == 'O') dfs(board, make_pair(m - 1, j), '#');
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, make_pair(i, 0), '#');
            if (board[i][n - 1] == 'O') dfs(board, make_pair(i, n - 1), '#');
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, pair<int, int>&& position, const char& fill) {
        if (position.first < 0 || position.first >= m
            || position.second < 0 || position.second >= n) {
                return;
        }
        if (board[position.first][position.second] != 'O') return;
        board[position.first][position.second] = fill;
        for (auto&& direction: directions) {
            dfs(board, make_pair(position.first + direction.first, position.second + direction.second), fill);
        }
    }

private:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m;
    int n;
};
// @lc code=end

