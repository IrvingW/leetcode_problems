/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 *
 * https://leetcode-cn.com/problems/reshape-the-matrix/description/
 *
 * algorithms
 * Easy (70.46%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    52.6K
 * Total Submissions: 74.7K
 * Testcase Example:  '[[1,2],[3,4]]\n1\n4'
 *
 * 在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。
 *
 * 给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。
 *
 * 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
 *
 * 如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
 *
 * 示例 1:
 *
 *
 * 输入:
 * nums =
 * [[1,2],
 * ⁠[3,4]]
 * r = 1, c = 4
 * 输出:
 * [[1,2,3,4]]
 * 解释:
 * 行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
 *
 *
 * 示例 2:
 *
 *
 * 输入:
 * nums =
 * [[1,2],
 * ⁠[3,4]]
 * r = 2, c = 4
 * 输出:
 * [[1,2],
 * ⁠[3,4]]
 * 解释:
 * 没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
 *
 *
 * 注意：
 *
 *
 * 给定矩阵的宽和高范围在 [1, 100]。
 * 给定的 r 和 c 都是正数。
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // check
        if (mat.empty()) return mat;
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat;

        vector<vector<int>> result(r, vector<int>(c, 0));
        int index = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                index += 1;
                result[index / c][index % c] = mat[i][j];
            }
        }
        return result;
    }
};
// @lc code=end

