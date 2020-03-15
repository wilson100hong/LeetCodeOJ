#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
  int r;
  int c;
  int v;

  bool operator < (const Cell& other) const {
    // smaller the first
    return other.v < v;
  }
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = grid[0][0];

    priority_queue<Cell> pq;
    vector<vector<bool>> visit(n, vector<bool>(n, false));

    pq.push({0,0,grid[0][0]});
    visit[0][0] = true;
    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      ans = max(ans, top.v);
      for (int d=0;d<4;++d) {
        int nr = top.r + dr[d], nc = top.c + dc[d];
        if (0 <= nr && nr < n && 0 <= nc && nc < n && !visit[nr][nc]) {
          if (nr == n-1 && nc == n-1) {
            return max(ans, grid[nr][nc]);
          }
          pq.push({nr, nc, grid[nr][nc]});
          visit[nr][nc] = true;
        }
      }
    }
    return ans;
  }
};


int main() {
  vector<vector<int>> input = {
    {0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}
  };
  Solution sol;
  cout << sol.swimInWater(input) << endl;
}
