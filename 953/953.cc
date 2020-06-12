#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool isAlienSorted(vector<string>& words, string order) {
      map<char, int> order_map;
      int index = 0;
      order_map['\0'] = index++;   // '∅' is 0
      for (char c : order) {
        order_map[c] = index++; 
      }

      auto compare_order = [&order_map](const string& s1, const string& s2) {
        int n = max(s1.size(), s2.size());
        for (int i=0;i<n;++i) {
          char c1 = s1.size() > i ? s1[i] : '\0';
          char c2 = s2.size() > i ? s2[i] : '\0';
          int o1 = order_map[c1], o2 = order_map[c2];
          cout << "o1: " << o1 << endl;
          cout << "o2: " << o2 << endl;
          if (o1 > o2) {
            cout << "#1" << endl;
            return false;
          }
        }
        return true;
      };

      for (int i=0;i<words.size()-1;i++) {
        if (!compare_order(words[i], words[i+1])) {
          cout << words[i] << endl;
          cout << words[i+1] << endl;
          return false;
        }
      }

      return true;
    }
};

int main() {
  vector<string> input = {"hello","leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  Solution sol;

  cout << sol.isAlienSorted(input, order) << endl;
}
