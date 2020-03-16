#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
string lastSubstring(string s) {
  int n = s.size();
  int i = 0, j = 1, k = 0;
  while (j+k < n) {
    //cout << "-------------" << endl;
    //cout << "s[i..k] = " << s.substr(i, k+1) << endl;
    //cout << "s[j..k] = " << s.substr(j, k+1) << endl;
    //cout << "-------------" << endl;

    if (s[i+k] == s[j+k]) {
      k++;
    } else if (s[i+k] > s[j+k]) {
      j = j + k + 1;
      k = 0;
    } else {
      i = max(j, i + k + 1);
      j = i + 1;

      k = 0;
    }
  }

  return s.substr(i);
}
};

int main() {
  //string input = "leetcode";
  //string input = "cacacb";
  string input = "vmjtxddvzmwrjvfamgpoowncslddrkjhchqswkamnsitrcmnhn";
  Solution sol;
  cout << sol.lastSubstring(input) << endl;
}
