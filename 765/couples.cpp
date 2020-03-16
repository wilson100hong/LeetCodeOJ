#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // Get index of the couple
  int couple(int i) {
    if (i % 2 == 0) return i + 1;
    return i - 1;
  }

  int minSwapsCouples(vector<int>& row) {
    vector<int> pos(row.size(), -1);
    for (int i=0;i<row.size();++i) {
      pos[row[i]] = i;
    }

    vector<int> ready(row.size(), false);

    int switchs = 0;
    for (int i=0;i<row.size(); i+=2) {
      if (ready[i]) continue;  // Already coupled.

      // We fix row[i] and search for its pair.
      while (row[i+1] != couple(row[i])) {
        int x = row[i+1];
        int y = couple(x);
        int y_pos = pos[y];
        int z_pos = (y_pos % 2 == 0 ? y_pos + 1 : y_pos - 1);
        int z = row[z_pos];

        swap(row[i+1], row[z_pos]);
        swap(pos[x], pos[z]);
        switchs++;
        ready[z_pos] = true;
      }
    }

    return switchs;
  }
};

int main() {
  vector<int> row = {
    0,2,1,3
  };
  Solution sol;
  cout << sol.minSwapsCouples(row) << endl;
}
