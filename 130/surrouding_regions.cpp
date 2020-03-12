#include <vector>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Cell {
  int r;
  int c;
};

#define BOARD 'B'

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;

    vector<vector<char>> copy = board;

    int h = board.size(), w = board[0].size();

    queue<Cell> q;
    for (int r=0;r<h;++r) {
      if (board[r][0] == 'O') {
        q.push({r, 0});
        copy[r][0] = BOARD;
      }
      if (board[r][w-1] == 'O') {
        q.push({r, w-1});
        copy[r][w-1] = BOARD;
      }
    }
    for (int c=1;c<w-1;++c) {
      if (board[0][c] == 'O') {
        q.push({0, c});
        copy[0][c] = BOARD;
      }
      if (board[h-1][c] == 'O') {
        q.push({h-1, c});
        copy[h-1][c] = BOARD;
      }
    }

    while (!q.empty()) {
      auto cell = q.front();  q.pop();
      //copy[cell.r][cell.c] = BOARD;
      for (int d=0;d<4;++d) {
        int nr = cell.r + dr[d];
        int nc = cell.c + dc[d];
        if (0 <= nr && nr < h && 0 <= nc && nc < w && copy[nr][nc] == 'O') {
          q.push({nr, nc});
          copy[nr][nc] = BOARD;
        }
      }
    }

    for (int r=0;r<h;++r) {
      for (int c=0;c<w;++c) {
        if (copy[r][c] == 'O') {
          board[r][c] = 'X';
        }
      }
    }
  }
};


int main() {
  Solution sol;
  //vector<vector<char>> mat = 
  //{
    //{'X','X','X','X'},
    //{'X','O','O','X'},
    //{'X','X','O','X'},
    //{'X','O','X','X'}
  //};
  vector<vector<char>> mat = 
  {
    {'O'}
  };
  sol.solve(mat);
  for (auto& row : mat) {
    for (auto& c : row) {
      cout << c << " ";
    }
    cout << endl;
  }
}
