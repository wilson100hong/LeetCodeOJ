#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DisjointSet {
public:
  DisjointSet(int n) {
    group_.assign(n, 0);
    size_.assign(n, 1);
    for (int i=0;i<n;++i) {
      group_[i] = i;
    }
    num_groups_ = n;
  }

  int find(int u) {
    if (u != group_[u]) {
      group_[u] = find(group_[u]);
    }
    return group_[u];
  }

  void join(int u, int v) {
    int gu = find(u), gv = find(v);
    if (gu == gv) return;
    if (size_[gu] > size_[gv]) {
      group_[gv] = gu;
      size_[gu] += size_[gv];
    } else {
      group_[gu] = gv;
      size_[gv] += size_[gu];
    }
    num_groups_--;
  }

  int numGroups() {
    return num_groups_;
  }

private:
  vector<int> group_;
  vector<int> size_;
  int num_groups_;
};

class Solution {
public:
  bool similar(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;  // Should not happen
    int diff_at = -1;
    int i=0;
    while (i < s1.size() && s1[i] == s2[i]) {
      i++;
    }
    if (i == s1.size()) return true;  // s1 == s2
    int d = i++;
    while (i < s1.size() && s1[i] == s2[i]) {
      i++;
    }

    if (i == s1.size()) return false;  // only differ one char 

    if (s1[d] != s2[i] || s1[i] != s2[d]) return false;
    i++;
    while (i < s1.size() && s1[i] == s2[i]) {
      i++;
    }
    return i == s1.size();
  }

  int numSimilarGroups(vector<string>& A) {
    unordered_set<string> B;
    for (const string& s : A) {
      B.insert(s);
    }

    vector<string> C(B.begin(), B.end());

    DisjointSet ds(C.size());

    for (int i=0;i<C.size()-1;++i) {
      for (int j=i+1;j<C.size();++j) {
        if (ds.find(i) != ds.find(j)) {
          if (similar(C[i], C[j])) {
            //cout << "join " << C[i] << " and " << C[j] << endl;
            ds.join(i, j);
          }
        }
      }
    }
    return ds.numGroups();
  }
};

int main() {
  vector<string> input = {
    //"tars","rats","arts","star"
    "jvhpg","jhvpg","hpvgj","hvpgj","vhgjp"
  };
  Solution sol;
  cout << sol.numSimilarGroups(input) << endl;
}
