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
    TreeNode* bstToGst(TreeNode* root) {
        rec(root, 0);
        return root;
    }
    
    // Return sum of the subtree
    int rec(TreeNode* node, int accum) {
        // accum is the sum > node->val
        if (node == nullptr) {
            return 0;
        }
        
        int sum = node->val;
        if (node->right) {
            sum += rec(node->right, accum);
        }
        
        node->val = sum + accum;
        
        if (node->left) {
            sum += rec(node->left, node->val);
        }
        
        return sum;
    }
};
