/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.85%)
 * Likes:    1079
 * Dislikes: 0
 * Total Accepted:    203.5K
 * Total Submissions: 291.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 * 返回如下的二叉树：
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildSubTree(preorder, make_pair(0, preorder.size() - 1),
                            inorder, make_pair(0, inorder.size() - 1));
    }

private:
    TreeNode* buildSubTree(const vector<int>& preorder, pair<int, int> preOrderRange,
                            const vector<int>& inorder, pair<int, int> inOrderRange) {
        int rootValue = preorder[preOrderRange.first];
        TreeNode* node = new TreeNode(rootValue);
        if (preOrderRange.second == preOrderRange.first) {
            return node;
        }
        int leftTreeSize = find(inorder.begin() + inOrderRange.first,
                                inorder.begin() + inOrderRange.second + 1,
                                rootValue) - (inorder.begin() + inOrderRange.first);
        int rightTreeSize = preOrderRange.second - preOrderRange.first - leftTreeSize;
        if (leftTreeSize > 0) {
            node->left = buildSubTree(preorder, make_pair(preOrderRange.first + 1, preOrderRange.first + leftTreeSize),
                                        inorder, make_pair(inOrderRange.first, inOrderRange.first + leftTreeSize - 1));
        }
        if (rightTreeSize > 0) {
            node->right = buildSubTree(preorder, make_pair(preOrderRange.first + leftTreeSize + 1, preOrderRange.second),
                                        inorder, make_pair(inOrderRange.first + leftTreeSize + 1, inOrderRange.second));
        }
        return node;
    }
};
// @lc code=end

