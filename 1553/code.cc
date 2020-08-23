#include <vector>
#include <iostream>

#define MAX 10000000
using namespace std;
class Solution {
public: 
    int rec(int n) {
        if (n < MAX && DP[n] != 0) return DP[n];
        
        int best;
        if (n >= 1000) {
          best = 1 + (n % 2) + rec(n/2);
          best = min(best, 1 + (n % 3) + rec(n/3));
        } else {
          best = 1 + rec(n-1);
          if (n % 2 == 0) {
              best = min(best, 1 + rec(n / 2));
          }
          if (n % 3 == 0) {
              best = min(best, 1 + rec(n / 3));    
          }
        }

        if (n < MAX) {    
          DP[n] = best;
        }
        return best;
    }
    
    int minDays(int n) {
        DP.assign(MAX, 0);
        DP[1] = 1;
        return rec(n);
    }
    
    vector<int> DP;
};

int main() {
  Solution sol;
  //for (int i = 1; i < 1000; ++i) {
  cout << sol.minDays(859858811) << endl;
 //}
}
