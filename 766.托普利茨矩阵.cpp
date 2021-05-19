/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 *
 * https://leetcode-cn.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (70.84%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    52.2K
 * Total Submissions: 73.7K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * 给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。
 *
 * 如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * 输出：true
 * 解释：
 * 在上述矩阵中, 其对角线为:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
 * 各条对角线上的所有元素均相同, 因此答案是 True 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2],[2,2]]
 * 输出：false
 * 解释：
 * 对角线 "[1, 2]" 上的元素不同。
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * 0
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
 * 如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
 *
 *
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int c = n - 1; c >= 0; c--) {
            int cur = matrix[0][c];
            int col = c + 1;
            for (int r = 1; r < m; r++) {
                if (col > n - 1) {
                    break;
                }
                if (cur != matrix[r][col]) {
                    return false;
                }
                col += 1;
            }
        }
        for (int r = 1; r < m; r++) {
            int cur = matrix[r][0];
            int row = r + 1;
            for (int c = 1; c < n; c++) {
                if (row > m - 1) {
                    break;
                }
                if (cur != matrix[row][c]) {
                    return false;
                }
                row += 1;
            }
        }
        return true;

    }
};
// @lc code=end

