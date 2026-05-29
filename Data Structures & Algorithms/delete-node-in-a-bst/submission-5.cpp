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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;

        // Search for target node
        while (curr && curr->val != key) {
            parent = curr;

            if (key < curr->val) {
                curr = curr->left;
            }
            else if (key > curr->val) {
                curr = curr->right;
            }
        }

        // Key does not exist in tree
        if (curr == nullptr) {
            return root;
        }

        // Both child exist
        if (curr->left && curr->right) {
            TreeNode* succParent = curr;
            TreeNode* succ = curr->right;

            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }

            curr->val = succ->val;

            parent = succParent;
            curr = succ;
        }

        TreeNode* child = nullptr;

        if (curr->left) {
            child = curr->left;
        }
        else {
            child = curr->right;
        }

        if (!parent) {
            delete curr;
            return child;
        }

        if (parent->left == curr) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }

        delete curr;
        return root;
    }
};