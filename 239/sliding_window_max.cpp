#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;  // index, value
        vector<int> result;
        
        for (int i=0;i<k-1;++i) {
            while (!q.empty() && q.back().second < nums[i]) {
                q.pop_back();
            }
            q.push_back({i, nums[i]});
        }

        for (int i=k-1;i<nums.size();++i) {
            while (!q.empty() && (i - q.front().first >= k)) {
                q.pop_front();
            }
            // TODO: wrong
            while (!q.empty() && q.back().second < nums[i]) {
                q.pop_back();
            }
            q.push_back({i, nums[i]});

            result.push_back(q.front().second);
        }
        return result;
    }
};

int main() {
    //vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
    //int k = 3;
    vector<int> input = {1, 3, 1, 2, 0, 5};
    int k = 3;
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(input, k);
    for (int r : result) {
        cout << r << " " ;
    }
    cout << endl;
}
