/*
 *
 * 2017/12/04
 *
 *  
 * TIPS: DP to save time
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
typedef unordered_map<string, vector<int>> DPMap;

class Solution {
public:
    bool is_op(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    int compute(char op, int l, int r) {
        if (op == '+') return l + r;
        if (op == '-') return l - r;
        if (op == '*') return l * r;
        return 0;
    }

    vector<int> diffWaysToComputeWithDP(
            const vector<int>& nums, const vector<char>& ops, int ops_start, int ops_end, DPMap& dp) {
        string key = to_string(ops_start) + "$" + to_string(ops_end);
        if (dp.count(key) != 0) return dp[key];

        vector<int> res;
        // recursive termination 
        if (ops_start == ops_end) {
            res = vector<int>{nums[ops_start]};
        } else {
            for (int i=ops_start;i<ops_end;++i) {
                char op = ops[i];
                vector<int> left = diffWaysToComputeWithDP(nums, ops, ops_start, i, dp);
                vector<int> right = diffWaysToComputeWithDP(nums, ops, i+1, ops_end, dp);
                for (int l:left) {
                    for (int r:right) {
                        res.push_back(compute(op, l, r));
                    }
                }
            }
        }

        dp[key] = res;
        return res;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        // tokenization
        int accum = 0;
        bool is_num = false;
        for (int i=0;i<input.size();++i) {
            char c = input[i];
            if (is_op(c)) {
                if (is_num) {
                    nums.push_back(accum);
                    accum = 0;
                    is_num = false;
                }
                ops.push_back(c);
            } else {
                accum = accum * 10 + (c-'0');
                is_num = true;
            }
        }
        if (is_num) {
            nums.push_back(accum);
        }
        DPMap dp;
        return diffWaysToComputeWithDP(nums, ops, 0, ops.size(), dp);
    }
};


int main() {
    Solution sol;
    string s = "2*3-4*5";
    vector<int> ans = sol.diffWaysToCompute(s);
    for (int a : ans) {
        cout << a << endl;
    }

}
