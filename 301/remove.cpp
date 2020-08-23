#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<string> removeInvalidParentheses(string s) {
      vector<string> res;
      Remove(s, 0, 0, {'(', ')'}, &res);
      return res;
    }

    void Remove(string s, int si, int sj, const vector<char>& pp, vector<string>* res) {
      int cnt = 0;
      for (int i=si;i<s.size();++i) {
        if (s[i] == pp[0]) {
          cnt++;
        } else if (s[i] == pp[1]) {
          cnt--;
          if (cnt < 0) {
            for (int j=sj;j<=i;++j) {
              if (s[j] == pp[1] && 
                  (j==sj || s[j-1] != pp[1])) {
                string ns = s.substr(0, j) + s.substr(j + 1, s.size());
                Remove(ns, i, j, pp, res);
              }        
            }
            return;  // No need to continue.
          }
        }
      }

      if (cnt == 0) {
        if (pp[0] == ')') {
          reverse(s.begin(), s.end());
        }
        res->push_back(s);
      } else {
        reverse(s.begin(), s.end());
        Remove(s, 0, 0, {')', '('}, res);
      }
    }
};

int main() {
  Solution sol;
  vector<string> ans;
  ans = sol.removeInvalidParentheses("()())()");
  for(const auto& a : ans) {
    cout << a << endl;
  }
  ans = sol.removeInvalidParentheses("(a)())()");
  for(const auto& a : ans) {
    cout << a << endl;
  }
  ans = sol.removeInvalidParentheses(")(");
  for(const auto& a : ans) {
    cout << a << endl;
  }

}
