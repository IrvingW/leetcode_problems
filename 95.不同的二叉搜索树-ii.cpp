/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        genSubTrees(1, n, result);
        return result;
    }
private:
    void genSubTrees(int start, int end, vector<TreeNode*> subTrees) {
        if (start > end) {
            subTrees.push_back(NULL);
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubTree;
            vector<TreeNode*> rightSubTree;
            genSubTrees(start, i - 1, leftSubTree);
            genSubTrees(i + 1, end, rightSubTree);
            for (auto pLNode: leftSubTree) {
                for (auto pRNode: rightSubTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = pLNode;
                    root->right = pRNode;
                    subTrees.push_back(root);
                }
            }
        }
    }
};
// @lc code=end

