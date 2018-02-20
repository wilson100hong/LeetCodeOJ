// 
// use hash map + Manachar.
// Manachar is good to test all substr palindrome.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string reverse(const string& s) {
        string r = s;
        int i = 0, j = r.size() - 1;
        while (i < j) {
            swap(r[i], r[j]);
            i++;
            j--;
        }
        return r;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> R;
        for (int i=0;i<words.size();++i) {
            R[reverse(words[i])] = i; 
        }
        
        vector<vector<int>> ans;

        for (int i=0;i<words.size();++i) {
            const string& word = words[i];

            vector<int> M = manacher(word);
             
            // word as LEFT
            for (int k=0;k<=word.size();++k) {
                string left = word.substr(0, k);

                int m_index = word.size()+k;
                bool right_isp = (M[m_index] == M.size()-1-m_index);
                
                if (R.count(left) && right_isp) {
                    int j = R[left];
                    if (i != j) {
                        ans.push_back({i, j});
                    }
                }
            }
            // word as RIGHT
            for (int k=1;k<=word.size();++k) {
                string right = word.substr(k);

                int m_index = k;
                bool left_isp = (M[m_index] == m_index);
                if (R.count(right) && left_isp) {
                    int j = R[right];
                    if (i != j) {
                        ans.push_back({j, i});
                    }
                }
            }
        }
        
        return ans;
    }
    
    string preprocess(const string& s) {
        string p = "#";
        for (char c : s) {
            p = p + c + "#";
        }
        return p;
    }
    
    // return vector size 2*|s| + 1
    vector<int> manacher(string s) {
        s = preprocess(s);
        int n = s.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        for (int i=0;i<n;++i) {
            int i_mirror = 2*center - i;
            if (right > i) {
                p[i] = min(right - i, p[i_mirror]);
            } else {
                p[i] = 0;
            }
            while (
                i-p[i]-1 >= 0 &&
                i+p[i]+1 < n &&
                s[i-p[i]-1] == s[i+p[i]+1]) {
                p[i]++;
            }
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
        }
        return p;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    auto ans = sol.palindromePairs(words);
    for (auto& a : ans) {
        cout << a[0] << "," << a[1] << endl;
    }

}
