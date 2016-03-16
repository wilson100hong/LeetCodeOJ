// 1. This is KMP problem, be familiar how table is build
// 2. its a compare of S suffix between R(S reverse) prefix
//    compare starting from the end of S & R
// 3. If mismatch happens, let cursor of R fallback using table[]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // s.size() >= 2
  vector<int> lookupTable(string s) {
    // 1. build lookup table
    vector<int> table(s.size(), -1);
    table[0] = -1;
    table[1] = 0;
    int cnd = 0, pos = 2;
    while (pos < s.size()) {
      if (s[pos-1] == s[cnd]) {
        table[pos++] = ++cnd;
      } else if (table[cnd] != -1) {
        cnd = table[cnd];
      } else {
        table[pos++] = 0;
        cnd = 0;
      }
    }
    return table;
  }

  string shortestPalindrome(string s) {
    if (s.size() < 2) return s;
    vector<int> table = lookupTable(s);

    int i = s.size() - 1, j = 0;
    while (i >= 0) {
      cout << "i:" << i << ", j:" << j << endl;
      if (s[i] == s[j]) {
        i--; j++;
      } else if (table[j] != -1){
        j = table[j];
      } else {
        i--; j = 0;
      }
    }
    if (j == s.size()) return s;
    cout << "j" << j <<  endl;
    string append = s.substr(j);
    cout << "append: " << append << endl;
    int l = 0, r = append.size() - 1;
    while (l < r) {
      char c = append[l];
      append[l] = append[r];
      append[r] = c;
      l++, r--;
    }
    // reverse append
    return append + s;
  }
};

int main() {
  Solution sol;
  // string s = "PARTICIPATE IN PARACHUTE";
  // string s = "abcbaba";
  string s = "acecaaa";
  cout << sol.shortestPalindrome(s) << endl;
}
