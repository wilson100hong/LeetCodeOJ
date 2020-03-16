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
    TreeNode* getLeft(TreeNode* node) {
        return node == nullptr ? nullptr : node->left;    
    }
    
    TreeNode* getRight(TreeNode* node) {
        return node == nullptr ? nullptr : node->right;    
    }
            
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        
        TreeNode* node = new TreeNode(0);
        if (t1 != nullptr) node->val += t1->val;
        if (t2 != nullptr) node->val += t2->val;
        
        node->left = mergeTrees(getLeft(t1), getLeft(t2));
        node->right = mergeTrees(getRight(t1), getRight(t2));
        return node;
    }
};
