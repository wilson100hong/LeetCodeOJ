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
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        vector<TreeNode*> array;
        Inorder(root, &array);
        return Build(array, 0, array.size()-1);
    }
    
    void Inorder(TreeNode* node, vector<TreeNode*>* array) {
        if (!node) return;
        Inorder(node->left, array);
        array->push_back(node);
        Inorder(node->right, array);
    }
    
    TreeNode* Build(const vector<TreeNode*>& array, int l, int r) {
        if (l > r) return nullptr;
        int m = (l+r)/2;
        TreeNode* root = array[m];
        root->right = Build(array, m+1,r);
        root->left = Build(array,l,m-1);
        return root;
    }
};
