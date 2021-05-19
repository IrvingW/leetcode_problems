/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (63.38%)
 * Likes:    591
 * Dislikes: 0
 * Total Accepted:    69.2K
 * Total Submissions: 109.1K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * 给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
 * 请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * 输出：13
 * 解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[-5]], k = 1
 * 输出：-5
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == matrix.length
 * n == matrix[i].length
 * 1
 * -10^9
 * 题目数据 保证 matrix 中的所有行和列都按 非递减顺序 排列
 * 1
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int smaller = smallerCnt(matrix, mid);
            if (smaller < k) low = mid + 1;
            else if (smaller >= k) high = mid;
        }
        return low;
    }
private:
    int smallerCnt(vector<vector<int>>& matrix, int target) {
        int result = 0;
        int col = n - 1;
        for (int i = 0; i < n; i++) {
            for (int j = col; j >= 0; j--) {
                if (matrix[i][j] <= target) {
                    col = j;
                    result += (j + 1);
                    break;
                }
            }
        }
        return result;
    }
private:
    int n;
};
// @lc code=end
