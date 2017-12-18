#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    unordered_map<string, int> dp;  // dp for best
    unordered_map<string, string> rm;  // dp for reduce
    int best;  // so far the min steps to clear board

    int findMinStep(string board, string hand) {
        dp.clear();
        sort(hand.begin(), hand.end());
        best = -1;

        recFindMinStep(board, hand, 0);
        return best;
    }

    bool is_possible(const string& board, const string& hand) {
        unordered_map<char, int> count;
        for (char c : board) {
            count[c]++;
        }
        for (char c : hand) {
            if (count.count(c) != 0) {
                count[c]++;
            }
        }

        for (auto& kv : count) {
            if (kv.second < 3) return false;
        }
        return true;
    }

    string reduce(string s) {
        if (s.size() < 3) return s;

        if (rm.count(s) != 0) return rm[s];

        int cnt = 1;
        int pos = -1;
        for (int i=1;i<s.size();++i) {
            if (s[i] == s[i-1]) {
                cnt++;
                if (cnt >= 3) pos = i;
            } else if(cnt >= 3) {  // s[i] != s[i-1]
                break;
            } else {
                cnt = 1;
            }
        }

        if (pos == -1) {
            rm[s] = s;
        } else {
            rm[s] = reduce(s.erase(pos - cnt + 1, cnt));
        }
    
        return rm[s];
    }

    
    int recFindMinStepDP(string board, string hand, int steps) {
        string key = board + "$"+ hand;

        if (dp.count(key) != 0) return dp[key];

        dp[key] = recFindMinStep(board, hand, steps);
        return dp[key];
    }

    int recFindMinStep(string board, string hand, int steps) {
        // 1. terminate recurssion?
        if (board.empty()) {
            if (best == -1 || steps < best) {
                best = steps;
            }
            return steps;
        }

        // 2. cannot be better than best, terminate
        if (best != -1 && steps >= best) {
            return -1;
        }

        // 4. if not possible, terminiate
        if (!is_possible(board, hand)) {
            return -1;
        }
        

        // 5. try all balls on hands on each position of the board
        int ret = -1;
        for (int i=0;i<hand.size();++i) {
            if (i == 0 || hand[i] != hand[i-1]) {  // skip same color 
                char ball = hand[i];
                // TODO: optimize new_hand
                string new_hand(hand);
                new_hand.erase(i, 1);
                
                for (int j=0;j<=board.size();++j) {
                    // TODO: optimize new_board
                    string new_board(board);
                    new_board.insert(j, 1, ball);

                    new_board = reduce(new_board);
                    int ms = recFindMinStepDP(new_board, new_hand, steps + 1);
                    if (ms != -1) {
                        if (ret == -1 || ms < ret) {
                            ret = ms;
                        }
                    }
                }
            }
        }
        return ret;
    }
    
};

int main() {
    //string board, hand;
    //cout << "board:" << endl;
    //cin >> board;
    //cout << "hand:" << endl;
    //cin >> hand;
    string board = "WRYYRWWRRWW";
    string hand = "WYBR";

    Solution sol;
    cout << sol.findMinStep(board, hand) << endl;
    
}
