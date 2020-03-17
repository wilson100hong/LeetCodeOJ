#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

class Solution {
public:
  pair<string, vector<int>> getIntervals(const string& str) {
    stringstream ss;
    vector<int> interval;

    int num_x = 0;
    for (int i=0;i<str.size();++i) {
      char c = str[i];
      if (c == 'X') {
        num_x++;
      } else {
        // 'L' and 'R'
        ss << c;
        interval.push_back(num_x);
        num_x = 0;
      }
    }

    interval.push_back(num_x);
    return {ss.str(), interval};
  }

  bool canTransform(string start, string end) {
    auto i1 = getIntervals(start), i2 = getIntervals(end);

    auto &s1 = i1.first, &s2 = i2.first;
    auto &v1 = i1.second, &v2 = i2.second;

    if (i1.first != i2.first) {
      //cout << "#1" << endl;
      return false;
    }
    if (v1.size() != v2.size()) {
      //cout << "#2" << endl;
      return false;
    }
    for (int i=0;i<v1.size()-1;++i) {
      if (v1[i] > v2[i]) {
        // Need to pass to right
        if (s1[i] != 'L') {
          //cout << "#3" << endl;
          return false;
        }
        v1[i+1] += (v1[i] - v2[i]);
      } else if (v1[i] < v2[i]) {
        // Need to borrow from right
        if (s1[i] != 'R') {
          //cout << "#4" << endl;
          return false;
        }
        v1[i+1] -= (v2[i] - v1[i]);
      }
    }
    return v1[v1.size()-1] == v2[v2.size()-1];
  }
};

int main() {
  Solution sol;
  cout << sol.canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
}
