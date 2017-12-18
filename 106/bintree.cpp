class Solution {
public:
    unordered_map<int, int> location;  // inorder index
    vector<int> ino;
    vector<int> posto;
    
    TreeNode* helper(int istart, int pstart, int len) {
        if (len <= 0) return nullptr;
        
        int val = posto[pstart + len - 1];
        TreeNode* node = new TreeNode(val);
        
        int index = location[val];
        
        int llen = index - istart;
        node->left = helper(istart, pstart, llen);
        int rlen = len - 1 - llen;
        node->right = helper(index + 1, pstart + llen, rlen);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0;i<inorder.size();++i) {
            location[inorder[i]] = i;
        }
        ino = inorder;
        posto = postorder;
        
        return helper(0, 0, ino.size());
        
    }
};
