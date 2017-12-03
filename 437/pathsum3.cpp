struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public: 
    int pathSumUp(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return (root->val == sum) + pathSumUp(root->left, sum - root->val) + pathSumUp(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return pathSumUp(root, sum) + pathSum(root->right, sum) + pathSum(root->left, sum);
    }
    
};
