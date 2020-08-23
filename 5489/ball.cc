#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool doable(vector<int>& pos, int m, int guess) {
        int last = pos[0];
        int i = 1;
        m--;
        while (m > 0 && i < pos.size()) {
            // advance i until pos[i] - last >= guess 
            while (i < pos.size() && pos[i] - last < guess) {
                i++;
            }
            if (i == pos.size()) break;
            m--;
            last = pos[i];
        }
        return m == 0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());   
        // Binary search
        int left = 1, right = position.back() - position.front();
        while (right > left + 1) {
            int mid = left + (right - left) / 2;
            //cout << "mid: " << mid << endl;
            if (doable(position, m, mid)) {
              left = mid;
            } else {
              right = mid - 1;
            }
        }
        if (right > left && doable(position, m, right)) {
            left = right;
        }
        return left;
    }
};

int main() {
  //vector<int> pos = {1,2,3,4,7};
  vector<int> pos = {79,74,57,22};
  Solution sol;
  cout << sol.maxDistance(pos, 4) << endl;
}
