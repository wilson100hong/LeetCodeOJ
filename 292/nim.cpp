// there is a pattern TTTF
// TTTFTTTFTTTF...
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        int r = (n-1) %4;
        return r!=3;
    }
};

int main() {
    Solution sol;
    cout << sol.canWinNim(1348820612) << endl;
}
