/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        genSquares(n, squares);
        queue<int> q;
        for (auto& num: squares) {
            q.push(num);
        }
        int result = 0;
        while(!q.empty()) {
            result += 1;
            int front = q.front();
            q.pop();
            if (front == n) {
                return result;
            }
            for (auto& square : squares) {
                int sum = square + front;
                if (sum > n) {
                    break;
                } else {
                    q.push(sum);
                }
            }
        }
    }

private:
    void genSquares(int n, vector<int>& squares) {
        for (int i = 1; i < n; i++) {
            int square = i * i;
            if (square > n) {
                break;
            }
            squares.push_back(square);
        }
    }
};
// @lc code=end

