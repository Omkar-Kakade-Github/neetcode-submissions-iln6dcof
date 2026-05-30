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
    int helper(TreeNode* root) {
        if (!root) return 0;

        int left  = helper(root->left);
        int right = helper(root->right);

        // if either subtree is unbalanced, propagate -1 up
        if (left == -1 || right == -1) return -1;

        // if current node is unbalanced, return -1
        if (abs(left - right) > 1) return -1;

        // otherwise return height as normal
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};