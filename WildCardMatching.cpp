// 1. use iterative solution
// 2. Naive recursive too slow
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // iterative solution
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    int lastStar = -1;
    int lastMatch = -1;
    while (i < s.size()) {
      // NOTE: j can be equal to p.size()! so check j inbound first
      if (j < p.size() && p[j] == '*') {
        lastStar = j++;
        lastMatch = i;
      } else if (j < p.size() && (p[j] == '?' || p[j] == s[i])) {
        i++; j++;
      } else if (lastStar != -1) {
        // traceback
          j = lastStar + 1;
          i = ++lastMatch;
      } else {
        return false;
      }
    }
    // for s = "", p = "*"
    while (j < p.size() && p[j] == '*') {
      j++;
    }
    return j == p.size();
  }

  // DP solution
  bool isMatchDP(string s, string p) {
    vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));

    dp[0][0] = true;
    for (int j = 1; j <= s.size(); ++j) {
      dp[0][j] = false;
    }
    for (int i = 1; i <= p.size(); ++i) {
      bool star = false;
      for (int j = 0; j <= s.size(); ++j) {
        if (p[i - 1] == '*') {
          star |= dp[i-1][j];
          dp[i][j] = star;
        } else if (p[i - 1] == '?') {
          dp[i][j] = (j == 0 ? false : dp[i-1][j-1]);
        } else {
          dp[i][j] = (j == 0 ? false :
            (p[i - 1] == s[j - 1]) && dp[i-1][j-1] );
          }
        }
      }
      return dp[p.size()][s.size()];
    }
};

int main() {
  Solution sol;

  cout << sol.isMatch(
  "a",
  "a*") << endl;
  /*
  cout << sol.isMatch(
  "abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab",
  "*aabb***aa**a******aa*") << endl;
  */

  /*
  cout << sol.isMatch(
    "",
    "") << endl;
    */
}
