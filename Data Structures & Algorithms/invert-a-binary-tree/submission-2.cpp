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

    TreeNode* switcher(TreeNode* root) {
        TreeNode* temp;

        temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        TreeNode* left_node;
        TreeNode* right_node;
    
        root = switcher(root);
        left_node = invertTree(root->left);
        right_node = invertTree(root->right);

        return root;
    }
};
