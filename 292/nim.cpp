// there is a pattern TTTF
// TTTFTTTFTTTF...
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canWinNim(int n) {
    return n % 4 != 0;
  }
};

int main() {
    Solution sol;
    cout << sol.canWinNim(1348820612) << endl;
}
