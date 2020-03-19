#include <iostream>
#include <cstdlib>
#include <vector>

#include <map>
using namespace std;

typedef unsigned long long ULL; 

class Solution {
  public:
    Solution(vector<int>& w) {
      cum.assign(w.size(), 0);
      cum[0] = w[0];
      for (int i=1;i<w.size();++i) {
        cum[i] = w[i] + cum[i-1];
        //cout << cum[i] << endl;
      }
      bound = cum[cum.size()-1];
      //cout << bound << endl;
    }


    int pickIndex() {
      ULL x = rand() % bound;  // pick
      return sample(x);
    }

    // binary search i where  cum_[i-1] < x <= cum_[i]
    int sample(ULL x) {
      int l = 0, r = cum.size()-1;
      while (l < r) {
        int m = (l + r) / 2;
        if (cum[m] <= x) {
          l = m + 1;
        } else {    
          r = m;
        }
      }
      return l;
    }
    vector<ULL> cum;
    ULL bound;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
int main() {
  vector<int> w = {3, 14, 1, 7};
  Solution obj(w);

  //for (int i=0;i<25;++i) {
    //cout << obj.sample(i) << endl;
  //}

  map<int, int> cnts;
  for (int i=0;i<300000;++i) {
    cnts[obj.pickIndex()]++;
  }

  int sum = 0;
  for (const auto& kv : cnts) {
    sum += kv.second;
  }

  for (const auto& kv : cnts) {
    cout << "percentage: " << kv.first << ": " << static_cast<double>(kv.second) / sum << endl;
  }
}
