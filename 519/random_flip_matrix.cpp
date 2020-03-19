class Solution {
 
public:
    Solution(int n_rows, int n_cols) {
        nr = n_rows;
        nc = n_cols;
        reset();
    }
    
    vector<int> flip() {
        // Fisher-Yates
        int r = total > 0 ? rand() % total : 0;
        total--;
        
        int x = holes.count(r) ? holes[r] : r;
        holes[r] = holes.count(total) ? holes[total] : total;
        return { x/nc, x%nc };
    }
    
    void reset() {
        total = nr*nc;
        holes.clear();
    }

    int nr;
    int nc;
    unordered_map<int, int> holes;
    int total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
