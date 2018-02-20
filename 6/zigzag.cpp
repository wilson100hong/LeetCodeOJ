class Solution {
public:
    string convert(string s, int numRows) {
        string ans = s;
        int NR = numRows - 1;
        for (int r=0, i=0;r<numRows;++r) {
            int j = r;
            bool v = true;  // down and up
            while (j < s.size()) {
                ans[i++] = s[j]; 
                if (NR == 0) {
                    j++;  
                } else if (r == 0 || r == NR) {
                    j += 2*NR;
                } else {
                    j += (v ? 2*(NR-r) : 2*r);
                    v = !v;
                }
            }
        }
        return ans;   
        
    }
};
