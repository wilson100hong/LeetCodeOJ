#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

#define TOP 0

struct II{
  int i;
  int j;
};

class DisjoinSet {
public:
  DisjoinSet(const vector<vector<int>>& grid) {
    h_ = grid.size();
    w_ = grid[0].size();
    group_.assign(h_*w_+1, TOP);
    size_.assign(h_*w_+1, 0);

    // group_[0] is TOP.
    for (int i=1;i<group_.size();++i) {
      group_[i] = i;
      size_[i] = 1;
    }

  }

  int getIndex(II p) {
    return p.i*w_ + p.j+ 1;
  }

  int find(II p) {
    return find(getIndex(p));
  }

  int find(int index) {
    if (group_[index] != index) {
      group_[index] = find(group_[index]);
    }
    return group_[index];
  }

  void join(II pu, II pv) {
    join(getIndex(pu), getIndex(pv));
  }

  void join(int u, int v) {
    int gu = find(u), gv = find(v);
    if (gu != gv) {
      if (gu == TOP) {
        group_[gv] = gu;
        size_[gu] += size_[gv];
      } else {
        group_[gu] = gv;
        size_[gv] += size_[gu];
      }
    }
  }

  int size(int u) {
    return size_[find(u)];
  }

  void dump(vector<vector<int>>& grid) {
    for (int i=0;i<grid.size();++i) {
      for (int j=0;j<grid[i].size();++j) {
        if (grid[i][j] == -1) cout << ".";
        else cout << grid[i][j];
      }
      cout << endl;
    }
    cout << endl;
    for (int i=0;i<group_.size();++i) {
      cout << "i " << i << ", group=" << find(i) << ", size=" << size(i) << endl;
    }
  }

private:
  int h_;
  int w_;
  vector<int> group_;
  vector<int> size_;
};

class Solution {
public:

  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    DisjoinSet ds(grid);

    // 1. delete hit bricks from grid
    for (const auto& hit : hits) {
      grid[hit[0]][hit[1]]--;
    }
    
    int h = grid.size(), w = grid[0].size();
    // 2. join all islands from grids
    for (int i=0;i<h;++i) {
      for (int j=0;j<w;++j) {
        if (grid[i][j] != 1) continue;
        if (i == 0) ds.join(ds.getIndex({i,j}), TOP);
        if (i<h-1 && grid[i+1][j] == 1) ds.join({i,j}, {i+1,j});
        if (j<w-1 && grid[i][j+1] == 1) ds.join({i,j}, {i,j+1});
      }
    }

    // 3. add hits back in reverse
    vector<int> ans(hits.size(), 0);

    for (int k=hits.size()-1;k>=0;--k) {
      auto& hit = hits[k];
      int i = hit[0], j = hit[1];
      if (++grid[i][j] != 1) {
        //ds.dump(grid);
        continue;
      }

      int old_size = ds.size(TOP);
      // join 4 adjacent cells
      if (i == 0) ds.join(ds.getIndex({i,j}), TOP);
      for (int d=0;d<4;++d) {
        int ni = i+di[d], nj = j+dj[d];
        if (0<=ni && ni<h && 0<=nj && nj<w && grid[ni][nj]==1) {
          ds.join({i,j}, {ni, nj});
        }
      }
      
      if (old_size != ds.size(TOP)) {
        ans[k] = ds.size(TOP) - old_size - 1;
      }

      //ds.dump(grid);
    }
    return ans;
  }

};

 int main() {
   vector<vector<int>> grid = {
     //{1,0,0,0}, {1,1,1,0}
     //{1,0,0,0}, {1,1,0,0}
     //{1,0,1}, {1,1,1}
     {{1,1,1},{0,1,0},{0,0,0}}
   };

   vector<vector<int>> hits = {
     //{1,0}
     //{1,1},{1,0}
     //{0,0},{0,2},{1,1}
     {0,2},{2,0},{0,1},{1,2}
   };

   Solution sol;
   auto ans = sol.hitBricks(grid, hits);
   for (int a : ans) 
     cout << a << endl;
 }

