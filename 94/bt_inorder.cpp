/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& array) {
        if (node == nullptr) return;
        inorder(node->left, array);
        array.push_back(node->val);
        inorder(node->right, array);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> array;
        inorder(root, array);
        return array;
    }

};
