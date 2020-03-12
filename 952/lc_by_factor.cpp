// Be aware that 1 is specical
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  void buildPrimes() {
    constexpr int kMax = 100001;
    bool IS_PRIME[kMax];
    for (int i=0;i<kMax;++i) {
      IS_PRIME[i] = true;
    }

    for (int i=2;i*i<=kMax;++i) {
      if (!IS_PRIME[i]) continue;
      for (int j=i*2;j<kMax;j+=i) {
        IS_PRIME[j] = false;
      }
    }

    for (int i=2;i<kMax;++i) {
      if (IS_PRIME[i]) {
        primes_.push_back(i);
      }
    }
  }

  vector<int> getFactors(int n) {
    if (n==1) return {1};
    vector<int> res;
    for (int p : primes_) {
      if (p*p > n) break;
      if (n % p == 0) {
        while (n % p == 0) {
          n /= p;
        }
        res.push_back(p);
      }
    }

    if (n != 1) res.push_back(n);
    return res;
  }


  int largestComponentSize(vector<int>& A) {
    buildPrimes();
    unordered_map<int, int> fac2index;

    group_.assign(A.size(), -1);
    sz_.assign(A.size(), -1);
    for (int i=0;i<A.size();++i) {
      group_[i] = i;
      sz_[i] = 1;
    }

    for (int i=0;i<A.size();++i) {
      int n = A[i];
      auto factors = getFactors(n);

      for (int factor : factors) {
        if (!fac2index.count(factor)) {
          fac2index[factor] = i;
        }
        join(i, fac2index[factor]);
      }
    }

    int max_sz = 0;
    for (const auto& z : sz_) {
      max_sz = max(max_sz, z);
    }
    return max_sz;
  }

  void join(int u, int v) {
    int gu = getGroup(u), gv = getGroup(v);
    if (gu == gv) return;
    if (sz_[gu] > sz_[gv]) {
      group_[gv] = gu;
      sz_[gu] += sz_[gv];
    } else {
      group_[gu] = gv;
      sz_[gv] += sz_[gu];
    }
  }

  int getGroup(int u) {
    if (group_[u] != u) {
      group_[u] = getGroup(group_[u]);
    }
    return group_[u];
  }

  vector<int> primes_;
  vector<int> group_;
  vector<int> sz_;
};

int main() {
  Solution sol;
  vector<int> input;
  input = {20,50,9,63};
  cout << sol.largestComponentSize(input) << endl;
}

