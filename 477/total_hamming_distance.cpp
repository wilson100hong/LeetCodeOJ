ass Solution {
public:

    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int one_cnts[32]  = {0};
        for (int i : nums) {
            for (int j=0;j<32;++j) {
                if (i & 1) {
                    one_cnts[j]++;
                }
                i = i>>1;
            }
        }
        int total = 0;
        for (int j=0;j<32;++j) {
            total += one_cnts[j]*(n-one_cnts[j]);
        }
        return total;
    }
};
