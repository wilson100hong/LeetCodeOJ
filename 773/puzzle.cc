#include <vector>
#include <unordered_set>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

struct VectorHash {
  size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    size_t seed = 0;
    for (int i : v) {
      seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    return seed;
  }
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

typedef vector<int> State;
typedef unordered_set<State, VectorHash>  StateSet;

class Solution {
  public:
    bool Solved(const State& state) {
      for (int i=0;i<5;++i) {
        if (state[i] != i+1) return false;
      }
      return state[5] == 0;
    }

    pair<int, int> GetEmptyRC(const State& state) {
      int i = 0;
      while (state[i] != 0 && i < state.size()) {
        i++;
      }
      return {i/3, i%3};
    }

    void DumpState(const State& state) {
      int x = 0;
      for(int i=0;i<2;++i) {
        for (int j=0;j<3;++j) {
          cout << state[x++] << ",";
        }
        cout << endl;
      }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
      State state;
      for (const auto& row : board) {
        for (int e : row) {
          state.push_back(e);
        }
      }
      queue<State> Q;
      Q.push(state);
      StateSet visit;
      visit.insert(state);
      int step = 0;

      while (!Q.empty()) {
        StateSet to_add;
        while (!Q.empty()) {
          State state = Q.front();
          cout << "state: " << endl;
          DumpState(state);
          Q.pop();
          if (Solved(state)) return step;
          int r, c;
          tie(r, c) = GetEmptyRC(state);
          cout << "r:"  << r << ", c:" << c << endl;

          for (int d=0;d<4;++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (0 <= nr && nr < 2 && 0 <= nc && nc < 3) {
              State n_state(state);
              swap(n_state[3*r + c], n_state[3*nr + nc]);
              if (!visit.count(n_state)) {
                visit.insert(n_state);
                to_add.insert(n_state);
              }
            }
          }
        }

        for (const auto& v : to_add) {
          Q.push(v);
        }
        step++;
      }
      return -1;
    }
};

int main() {
  vector<vector<int>> board = {{1,2,3},{4,0,5}};
  Solution sol;
  cout << sol.slidingPuzzle(board) << endl;
}
