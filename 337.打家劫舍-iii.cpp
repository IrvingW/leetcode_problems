/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
using namespace std;
class Solution {
public:
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
private:
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return make_pair<int, int>(0, 0);
        auto leftResult = dfs(node->left);
        auto rightResult = dfs(node->right);
        int selected = leftResult.second + rightResult.second + node->val;
        int notSelected = max(leftResult.first, leftResult.second) + max(rightResult.first, rightResult.second);
        return make_pair<int, int>(move(selected), move(notSelected));
    }
};
// @lc code=end

