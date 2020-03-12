#include <iostream>
#include <vector>
using namespace std;

#define UP 0
#define LF 1
#define DN 2
#define RT 3

class Solution {
public:
  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();

    // 1. construct "triangle"'s unions, each cell has 4 triangles, where
    // 0,1,2,3 denotes up, left, down, right pieces.
    group.assign(4*n*n, -1);
    for (int i=0;i<4*n*n;++i) {
      group[i] = i;
    }

    for (int r=0;r<n;++r) {
      for (int c=0;c<n;++c) {
        if (0 <= c && c < n-1) {
          // connect right to next colu's left
          join(getIndex(n, r, c, RT), getIndex(n, r, c+1, LF)); 
        }
        if (0 <=r && r < n-1) {
          // connect down to next row's top
          join(getIndex(n, r, c, DN), getIndex(n, r+1, c, UP)); 
        }
      }
    }

    for (int r=0;r<grid.size();++r) {
      for (int c=0;c<grid[r].size();++c) {
        if (grid[r][c] == ' ') {
          // connect all trianges in the cell.
          join(getIndex(n, r, c, UP), getIndex(n, r, c, LF)); 
          join(getIndex(n, r, c, DN), getIndex(n, r, c, RT)); 
          join(getIndex(n, r, c, UP), getIndex(n, r, c, DN)); 
        } else if (grid[r][c] == '/') {
          // connect (up, left)
          join(getIndex(n, r, c, UP), getIndex(n, r, c, LF)); 
          // connect (down, right)
          join(getIndex(n, r, c, DN), getIndex(n, r, c, RT)); 
        } else if (grid[r][c] == '\\') {
          // connect (up, right)
          join(getIndex(n, r, c, UP), getIndex(n, r, c, RT)); 
          // connect (down, left)
          join(getIndex(n, r, c, DN), getIndex(n, r, c, LF)); 
        }
      }
    }

    int cnt = 0;
    for (int i=0;i<4*n*n;++i) {
      if (group[i] == i) cnt++;
    }
    return cnt;
  }

  int getIndex(int n, int r, int c, int pos) {
    return 4*(n*r + c) + pos;
  }

  int getGroup(int i) {
    if (group[i] != i) {
      group[i] = getGroup(group[i]);
    }
    return group[i];
  }

  int join(int u, int v) {
    int gu = getGroup(u), gv = getGroup(v);
    if (gu == gv) return gu;
    group[gu] = v;
    return v;
  }

private:
  vector<int> group;
};

int main() {
  vector<string> input = { 
    "//",
  "/ "
  };

  Solution sol;
  cout << sol.regionsBySlashes(input) << endl;
}
