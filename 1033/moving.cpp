#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    // c > b > a
    int d1 = b - a, d2 = c - b;
    int max_moves = d1 + d2 - 2;

    int dmax = max(d1, d2), dmin = min(d1, d2);
    int min_moves = -1;
    if (dmax <= 1) {
      min_moves = 0;
    } else{   // dmax > 1, need at least 1 move
      min_moves = 1;
      if (dmin > 2) {
        min_moves++;
      }
    }
    return {min_moves, max_moves};
  }
};

int main() {
  Solution sol;
  //auto ans = sol.numMovesStones(1,2,5);
  //auto ans = sol.numMovesStones(4,3,2);
  auto ans = sol.numMovesStones(3,5,1);
  cout << ans[0]<< " " << ans[1] << endl;
}
