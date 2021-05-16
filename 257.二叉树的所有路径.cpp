/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        if (root == NULL) return results;
        backtracing(root, results);
        return results;
    }

private:
    void backtracing(TreeNode* root, vector<string>& results) {
        if (root->left == NULL && root->right == NULL) {
            results.push_back(to_string(root->val));
            return;
        }
        vector<string> leftResults;
        if (root->left != NULL) {
            backtracing(root->left, leftResults);
        }
        for (auto& subPath : leftResults) {
            results.push_back(to_string(root->val) + "->" + subPath);
        }
        vector<string> rightResults;
        if (root->right != NULL) {
            backtracing(root->right, rightResults);
        }
        for (auto& subPath : rightResults) {
            results.push_back(to_string(root->val) + "->" + subPath);
        }
        return;
    }
};
// @lc code=end

