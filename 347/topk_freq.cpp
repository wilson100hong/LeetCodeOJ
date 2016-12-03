#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // 0-based, find kth "descending"
    pair<int, int> findKth(vector<pair<int, int>>& vec, int left, int right, int kth) {
        pair<int, int> pivot = vec[right];
        int i=left, j=right-1, k=0;
        // partition. left part >= pivot, right < pivot 
        while (i<=j) {
            pair<int, int> cur = vec[i];
            if (cur.second >= pivot.second) {
                i++;
            } else {
                // swap
                vec[i] = vec[j];
                vec[j] = cur;
                j--;
                k++;
            }
        }

        int left_len = right - left - k;

        if (left_len == kth) {
            return pivot;
        } else if (left_len > kth) {
            return findKth(vec, left, right-k-1, kth);
        } else {
            return findKth(vec, right-k, right-1, kth-left_len-1);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) {
            if (!counts.count(n)) {
                counts[n] = 0;
            }
            counts[n]++;
        }

        // kth element in counts.
        vector<pair<int, int>> vec;
        for (auto& kv : counts) {
            vec.push_back({kv.first, kv.second});
        }

        pair<int, int> pivot = findKth(vec, 0, vec.size()-1, k-1);
        //cout << pivot.first << " " << pivot.second << endl;
        vector<int> ans;
        for (auto& kv : vec) {
            if (kv.second > pivot.second) {
                ans.push_back(kv.first);
            }
        }
        for (auto& kv : vec) {
            if (kv.second == pivot.second) {
                ans.push_back(kv.first);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {3, 0, 1, 0};
    vector<int> ans = sol.topKFrequent(input, 1);
    for (int a : ans) {
        cout << a << endl;
    }
}
