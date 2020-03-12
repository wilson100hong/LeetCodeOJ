#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findCircleNum(vector<vector<int>>& M) {
      int n = M.size();
      group_.assign(n, -1);
      for (int i=0;i<n;++i) {
        group_[i] = i;
      }

      for (int i=0;i<n-1;++i) {
        for (int j=i+1;j<n;++j) {
          if (M[i][j]) {
            join(i, j);
          }
        }
      }

      int cnt = 0;
      for (int i=0;i<group_.size();++i) {
        if (group_[i] == i) cnt++;
      }
      return cnt;
    }

    void join(int u, int v) {
      int gu = getGroup(u), gv = getGroup(v);
      if (gu == gv) return;
      group_[gu] = gv;
    }

    int getGroup(int u) {
      if (group_[u] != u) {
        group_[u] = getGroup(group_[u]);
      }
      return group_[u];
    }

  private:
    vector<int> group_;
};

int main() {
  vector<vector<int>> input = {
    {1,1,0},
    {1,1,0},
    {0,0,1}
  };
  Solution sol;
  cout << sol.findCircleNum(input) << endl;
}
