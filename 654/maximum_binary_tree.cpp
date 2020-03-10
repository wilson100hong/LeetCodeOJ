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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = nullptr;
        
        stack<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            TreeNode* child = nullptr;
            
            while (!stk.empty() && stk.top()->val < num) {
                child = stk.top();
                stk.pop();
            }
            
            // temp is nullptr or has val < num
            if (child != nullptr) {
                node->left = child;
            }
            
            TreeNode* parent = stk.empty() ? nullptr : stk.top();
            if (parent == nullptr) {
                root = node;
            } else {
                parent->right = node;
            }
            
            stk.push(node);
        }
        
        return root;
    }
};
