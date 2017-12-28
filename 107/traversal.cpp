#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> history;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        rec(root, 0);
        vector<vector<int>> ans;
        for (int i=history.size()-1; i>=0; --i) {
            ans.push_back(history[i]);
        }
        return ans;
    }
    
    void rec(TreeNode* node, int depth) {
        if (node == nullptr) return;
        
        while (history.size() <= depth) {
            history.push_back(vector<int>());
        }
        history[depth].push_back(node->val);
        rec(node->left, depth+1);
        rec(node->right, depth+1);
    }
};
