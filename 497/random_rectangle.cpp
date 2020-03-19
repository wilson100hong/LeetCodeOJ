class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        recs = rects;
        for (const auto& rec : rects) {
            int h = rec[2] - rec[0] + 1;
            int w = rec[3] - rec[1] + 1;
            weight.push_back(h*w);
        }
        
        cum.assign(weight.size(), 0);
        cum[0] = weight[0];
        for (int i=1;i<weight.size();++i) {
            cum[i] = cum[i-1] + weight[i];
        }
    }
    
    vector<int> pick() {
        // 1. pick the index of rec
        int x = rand() % cum[cum.size()-1];
        int l = 0, r = cum.size()-1;
        while (l < r) {
            int m = (l+r)/2;
            if (x >= cum[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        // 2. pick point from rec
    
        const auto& rec = recs[l];
        
        int h = rec[2] - rec[0] + 1;
        int w = rec[3] - rec[1] + 1;
        
        int rh = rand() % h;
        int rw = rand() % w;
        
        return {rh + rec[0], rw + rec[1]};
    }
    
    vector<vector<int>> recs;
    vector<int> weight;
    vector<int> cum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
