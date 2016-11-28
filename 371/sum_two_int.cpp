// negative number!
#include <iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        int dummy = 1;
        int digits = 1;
        while (dummy > 0) {
            dummy = dummy << 1;
            digits++;
        }
        int carry = 0;
        int result = 0;
        for (int offset=0;offset<digits;++offset) {
            int da = (a>>offset) & 1;
            int db = (b>>offset) & 1;
            int dr = da ^ db ^ carry;
            carry = (da & db) | (da & carry) | (db & carry);
            result = result | (dr<<offset);
        }
        return result;
    }
};


int main() {
    Solution sol;
    cout << sol.getSum(1, -8) << endl;
}
