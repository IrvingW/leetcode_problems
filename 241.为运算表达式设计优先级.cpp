/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

#include <string>
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        solveRecursive(expression, 0, expression.length() - 1, result);
        return result;
    }

private:
    set<char> opSet = {'+', '-', '*'};
    void solveRecursive(const string& expression, int start, int end, vector<int>& result) {
        if (start == end) {
            int number = atoi(expression.substr(start, 0).c_str());
            result.push_back(number);
            return;
        }
        for (int i = start; i <= end; i++) {
            if (opSet.count(expression[i]) > 0) {
                vector<int> leftResult;
                solveRecursive(expression, start, i - 1, leftResult);
                vector<int> rightResult;
                solveRecursive(expression, i + 1, end, rightResult);
                for (auto& l : leftResult) {
                    for (auto& r : rightResult) {
                        result.push_back(calculate(l, r, expression[i]));
                    }
                }
            }
        }
    }

    int calculate(const int& a, const int& b, const char& op) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        } else if (op == '*') {
            return a * b;
        } else {
            return 0;
        }
    }
};
// @lc code=end