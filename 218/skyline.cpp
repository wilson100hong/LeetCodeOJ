#include <algorithm>
#include <set>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Keypoint {
  int x;
  int h;
  bool left;
  int index;
};

bool CmpKeypoint(const Keypoint& kp1, const Keypoint& kp2) {
  if (kp1.x == kp2.x) {
    if (kp1.left == kp2.left) {
      return kp1.h < kp2.h;
    }
    return kp1.left;
  }
  return kp1.x < kp2.x;
}

class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      vector<Keypoint> kpts;
      int index = 0;
      for (const auto& b : buildings) {
        kpts.push_back({b[0], b[2], true, index});
        kpts.push_back({b[1], b[2], false, index});
        index++;
      }
      sort(kpts.begin(), kpts.end(), CmpKeypoint);

      vector<vector<int>> res;
      set<pair<int, int>> pq;  // {height, index}
      int prev_h = 0;

      int i = 0;
      while (i < kpts.size()) {
        int x = kpts[i].x;
        int j = i;
        while (j < kpts.size() && kpts[j].x == x) {
          if (kpts[j].left) {
            pq.insert({kpts[j].h, kpts[j].index});
          } else {
            pq.erase({kpts[j].h, kpts[j].index});
          }
          j++;
        }

        int h = pq.empty() ? 0 : pq.rbegin()->first;
        if (h != prev_h) {
          res.push_back({x, h});
          prev_h = h;
        }
        i = j;
      }

      return res;
    }
};

int main() {
  vector<vector<int>> input = {
    {2,9,10},
    {3,7,15},
    {5,12,12},
    {15,20,10},
    {19,24,8}
  };

  Solution sol;
  auto ans = sol.getSkyline(input);
  cout << "------" << endl;
  for (const auto& a : ans) {
    cout << "(" << a[0] << "," << a[1] << ")" << endl;
  }
}
