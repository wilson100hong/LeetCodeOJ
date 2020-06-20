#include <iostream>
#include <vector>
using namespace std;


typedef unsigned long long ULL;
struct DistIndex {
  ULL dist;
  int index;
};
class Solution {
  public:
    // Actually its distance^2
    ULL GetDist(const vector<int>& point) {
      return point[0] * point[0] + point[1] * point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      vector<DistIndex> dist_index_list;
      int index = 0;
      for (const auto& point : points) {
        dist_index_list.push_back({GetDist(point), index++});
      }

      QuickSelect(dist_index_list, 0, dist_index_list.size(), K - 1);

      vector<vector<int>> res;
      for (int i=0;i<K;++i) {
        res.push_back(points[dist_index_list[i].index]);
      }
      return res;
    }

    DistIndex QuickSelect(vector<DistIndex>& v, int begin, int end, int k) {
      int m = Partition(v, begin, end);
      if (m == k) {
        return v[m];
      } else if (m > k) {
        return QuickSelect(v, begin, m, k);
      } else {  // m < k
        return QuickSelect(v, m + 1, end, k);
      }
    }

    int Partition(vector<DistIndex>& v, int begin, int end) {
      int i = begin;
      int j = end - 1; // pivot
      int p = j;

      while (i < j) {
        if (v[i].dist <= v[p].dist) {
          i++;
        } else {
          j--;
          swap(v[i], v[j]);
        }
      }
      swap(v[p], v[j]);
      return j;
    }
};

int main() {
  Solution sol;
  //vector<vector<int>> points = {{1,3},{-2,2}};
  //auto ans = sol.kClosest(points, 1);
  
  //vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
  //auto ans = sol.kClosest(points, 2);
  
  //vector<vector<int>> points = {{0,1},{1,0}};
  //auto ans = sol.kClosest(points, 2);

  vector<vector<int>> points = {{6,10},{-3,3},{-2,5},{0,2}};
  auto ans = sol.kClosest(points, 3);
  for (const auto& a : ans) {
    cout << a[0] << "," << a[1] << endl;
  }
}
