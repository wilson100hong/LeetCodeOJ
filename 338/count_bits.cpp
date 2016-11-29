#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int cur = 1;
        while (cur <= num) {
            int last = cur/2;
            int len = cur;
            for (int i=0;i<len && cur<=num; ++i, ++cur) {
                // first part, copy last
                if (i<len/2) {
                    res.push_back(res[last+i]);
                } else {
                    res.push_back(res[last+i-len/2]+1);
                }
                // second part, use first party and plus 1
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> v = sol.countBits(16);
    for (int n : v ) {
        cout << n << " ";
    }
    cout << endl;
}
