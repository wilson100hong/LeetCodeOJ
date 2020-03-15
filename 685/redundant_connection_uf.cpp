// Care node with multiple "indegrees".
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class DisjointSet{
public:
  void add(int u) {
    if (!group_.count(u)) {
      group_[u] = u;
    }
  }

  void join(int u, int v) {
    // u-> v
    int gu = find(u), gv = find(v);
    if (gu == gv) return;
    group_[gv] = gu;
  }

  int find(int u) {
    if (group_[u] != u) {
      group_[u] = find(group_[u]);
    }
    return group_[u];
  }

private:
  unordered_map<int, int> group_;
};

class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    unordered_map<int, int> in_edge;
    vector<int> cand_edges;
    for (int i=0;i<edges.size();++i) {
      auto& edge = edges[i];
      // 2+ in edge
      if (in_edge.count(edge[1])) {
        cand_edges.push_back(in_edge[edge[1]]);
        cand_edges.push_back(i);
        break;
      }
      in_edge[edge[1]] = i;
    }

    DisjointSet ds;
    int skip_edge = cand_edges.empty() ? -1 : cand_edges[1];

    // Detect cycle
    int cycle_edge = -1;
    for (int i=0;i<edges.size();++i) {
      if (i == skip_edge) continue;
      int u = edges[i][0], v = edges[i][1];
      ds.add(u);
      ds.add(v);
      if (ds.find(u) == ds.find(v)) {
        // cycle
        cycle_edge = i;
        break;
      }
      ds.join(u, v); 
    }

    if (!cand_edges.empty()) {
      // If no cycle, cand_edges[0] is the edge to drop
      return cycle_edge == -1 ? edges[skip_edge] : edges[cand_edges[0]];
    }
    return edges[cycle_edge];
  }
};

int main() {
  vector<vector<int>> input = {
     {1,2}, {1,3}, {2,3}
     //{1,2}, {2,3}, {3,4}, {4,1}, {1,5}
    //{2,1},{3,1},{4,2},{1,4}
  };
  Solution sol;

  auto ans = sol.findRedundantDirectedConnection(input);
  cout << ans[0] << "," << ans[1] << endl;
}
