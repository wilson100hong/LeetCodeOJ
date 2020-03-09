#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

// Cumulative entry
struct CumEntry {
  LL c;  // Cumulative
  int n_i;  // Aggregation of nums[0] to nums[i]
};

bool CompCumEntry(const CumEntry& c1, const CumEntry& c2) {
  if (c1.c== c2.c) {
    return c1.n_i < c2.n_i;
  }
  return c1.c < c2.c;
}

class SegNode {
public:
  SegNode(const vector<CumEntry>& cums, int left, int right, SegNode* parent) {
    l = left;
    r = right;
    p = parent;

    lo = cums[l].c;
    up = cums[r].c;
    
    if (l == r) {
      cnt = 1;
      return;
    }

    // Create childs
    int m = (l + r)/2;
    lch = new SegNode(cums, l, m, this);
    rch = new SegNode(cums, m + 1, r, this);

    if (lch != nullptr) {
      cnt += lch->cnt;
    }
    if (rch != nullptr) {
      cnt += rch->cnt;
    }
  }

  bool IndexIn(int index) {
    return l <= index && index <= r;
  }

  int Query(LL lower, LL upper) {
    // No overlap.
    if (up < lower || lo > upper) {
      return 0;
    }

    // Fully covered
    if (lower <= lo && up <= upper) {
      return cnt;
    }

    // Partial overlapped, must have child
    return (lch == nullptr ? 0 : lch->Query(lower, upper)) +
           (rch == nullptr ? 0 : rch->Query(lower, upper));
  }

  // Index in cums.
  int l;
  int r;
  SegNode* p;  // parent
  // Value range [lower, upper] 
  LL lo;
  LL up;
  int cnt = 0;
  SegNode* lch = nullptr;  // Left child
  SegNode* rch = nullptr;  // Right child
};

class SegTree {
public:
  SegTree(const vector<CumEntry>& cums) {
    if (cums.empty()) {
      root = nullptr;
    } else {
      root = new SegNode(cums, 0, cums.size()-1, nullptr);
    }
  }

  void Remove(int index) {
    if (root == nullptr) return;
    SegNode* node = root;
    // 1. Find the node
    while (node->l != node->r) {
      // Not leaf
      if (node->lch != nullptr && index <= node->lch->r) {
        node = node->lch;
      } else if (node->rch != nullptr && index >= node->rch->l) {
        node = node->rch;
      } else {
        cout << "THERE IS BUG IN SEGTREE" << endl;
      }
    }

    while (node->p != nullptr) {
      node->cnt--;
      node = node->p;
    }
    node->cnt--;  // root
  }

  int Query(LL lower, LL upper) {
    if (root == nullptr) return 0;
    SegNode* node = root;
    return node->Query(lower, upper);
  }

  SegNode* root;
};

class Solution {
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<CumEntry> cums;
    for (int i=0;i<nums.size();++i) {
      cums.push_back({static_cast<LL>(nums[i]) + (i > 0 ? cums[i-1].c : 0), i});
    }

    sort(cums.begin(), cums.end(), CompCumEntry);

    // A mapping from nums index to cums index.
    vector<int> n2c_mapping(nums.size(), -1);
    int c_i = 0;
    for (const auto& cum : cums) {
      n2c_mapping[cum.n_i] = c_i++;
    }

    // Build SegmenTree
    SegTree* tree = new SegTree(cums);
    
    LL lo = static_cast<LL>(lower);
    LL up = static_cast<LL>(upper);
    int cnt = 0;
    for (int i=0;i<nums.size();++i) {
      cnt += tree->Query(lo, up);
      //cout << "cnt: " << cnt << endl;

      lo += nums[i];
      up += nums[i];
      tree->Remove(n2c_mapping[i]);  // Remove cumulative ending at nums[i] from segment tree.
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-2,5,-1};
  cout << sol.countRangeSum(nums, -2, 2) << endl;
}
