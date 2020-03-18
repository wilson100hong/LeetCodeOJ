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
    struct Result {
        bool is_bst;
        int sum;  // Only meaningful when is_bst == true
        int best;  // Best BST sum in sbutree.
    };
    
    int maxSumBST(TreeNode* root) {
        auto res = rec(root);
        return res.best;
    }
    
    // Return max sum of {including this node, among its subtree}
    Result rec(TreeNode* root) {
        if (!root) return {true, 0, 0};
        
        auto right_res = rec(root->right);
        auto left_res = rec(root->left);
        
        int best = max(right_res.best, left_res.best);
        if (!right_res.is_bst || 
            !left_res.is_bst ||
            (root->right && root->right->val <= root->val) ||
            (root->left && root->left->val >= root->val)) {
            return {false, 0, best};
        }
        
        int sum = root->val + right_res.sum + left_res.sum;
        return {true, sum, max(sum, best)};
    }
};
