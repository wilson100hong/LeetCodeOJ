#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

class Solution {
public:
  void dump(vector<vector<int>>& grid, unordered_set<int>& no_drop) {
    for (int i=0;i<grid.size();++i) {
      for (int j=0;j<grid[i].size();++j) {
        if (grid[i][j] == -1) cout << ".";
        else cout << grid[i][j];
      }
      cout << endl;
    }
    cout << "no drop: ";
    for (int nd : no_drop) cout << nd;
    cout << endl;
  }

  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    int h=grid.size(), w = grid[0].size();
    for (const auto& hit : hits) {
      grid[hit[0]][hit[1]]--;
    }

    unordered_set<int> no_drop;

    for (int j=0;j<w;++j) {
      if (grid[0][j] == 1) {
        dfs(grid, 0, j, no_drop);
      }
    }

    vector<int> ans(hits.size(), 0);

    for (int k=hits.size()-1;k>=0;--k) {
      auto& hit = hits[k];
      int i = hit[0], j = hit[1];
      ++grid[i][j];
      if (grid[i][j] != 1) continue;  // ans[k] = 0

      bool expand = 
        (i==0) ||   // attach to top
        (i-1 >= 0 && no_drop.count((i-1)*w + j)) ||  // adjacent is no_drop
        (i+1 < h && no_drop.count((i+1)*w + j)) ||
        (j-1 >=0 && no_drop.count(i*w + j-1)) ||
        (j+1 < w && no_drop.count(i*w + j+1));

      if (expand) {
        int old_size = no_drop.size();
        dfs(grid, hit[0], hit[1], no_drop);
        ans[k] = no_drop.size() - old_size - 1;  // minus hit one
      }
      //dump(grid, no_drop);
      //cout << "----" << endl;
    }
    return ans;
  }

  void dfs(vector<vector<int>>& grid, int i, int j, unordered_set<int>& no_drop) {
    int h=grid.size(), w = grid[0].size();
    int index = i*w + j;
    if (no_drop.count(index)) return;
    if (i<0 || i>=h || j<0 || j>=w || grid[i][j] != 1) return;

    //cout << "i: " << i << ", j: " << j << endl;
    no_drop.insert(index);
    for (int d=0;d<4;++d) {
      dfs(grid, i+di[d], j+dj[d], no_drop);
    }
  }

};

int main() {
  vector<vector<int>> grid = {
    //{1,0,0,0}, {1,1,1,0}
    //{1,0,0,0}, {1,1,0,0}
    {1,0,1}, {1,1,1}
  };

  vector<vector<int>> hits = {
    //{1,0}
    //{1,1},{1,0}
    {0,0},{0,2},{1,1}
  };

  Solution sol;
  auto ans = sol.hitBricks(grid, hits);
  for (int a : ans) 
    cout << a << endl;
}
