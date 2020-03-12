#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = 0;
    for (const auto& edge : edges) {
      n = max(n, edge[0]);
      n = max(n, edge[1]);
    }

    group_.assign(n, -1);
    for (int i=0;i<n;++i) {
      group_[i] = i;
    }

    //cout << "#2" << endl;

    for (const auto& edge : edges) {
      //cout << "#3" << endl;
      int u = edge[0]-1;
      int v = edge[1]-1;
      //cout << "u: " << u << ", v: " << v << endl;
      if (getGroup(u) == getGroup(v)) {
        return edge;
      }
      join(u, v);
    }
    return {};
  }

  int getGroup(int u) {
    if (group_[u] != u) {
      group_[u] = getGroup(group_[u]);
    }
    return group_[u];
  }

  void join(int u, int v) {
    int gu = getGroup(u), gv = getGroup(v);
    if (gu != gv) {
      group_[gu] = gv;
    }
  }

  vector<int> group_;
};

int main() {
  vector<vector<int>> input = {
    {1,2}, {2,3}, {3,4}, {1,4}, {1,5}
  };
  //]     // {{1,2}, {1,3}, {2,3}};
  Solution sol; 
  auto ans = sol.findRedundantConnection(input);
  cout << ans[0] << "," << ans[1] << endl;

}

