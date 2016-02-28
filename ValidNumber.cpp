#include <iostream>
using namespace std;

class Solution {
  public:
    bool isDigit(char c) {
      return '0' <= c && c <= '9';
    }

    // digits = [0-9]+
    bool isDigits(string s) {
      if (s.empty()) return false;
      for (int i = 0; i < s.size(); ++i) {
        if (!isDigit(s[i])) {
          return false;
        }
      }
      return true;
    }

    // int = 0 | [1-9][0-9]*
    bool isInt(string s) {
      if (s.empty()) return false;
      if (s.size() == 1) {
        return isDigit(s[0]);
      }
      if (s[0] == 0) return false;
      return isDigits(s);
    }

    // float = 
    //   1. digits[.[digits]]
    //   2. [digits].digits
    bool isFloat(string s) {
      if (s.empty()) return false;
      size_t found = s.find(".");
      if (found == string::npos) {  // digits
        return isDigits(s);
      } else if (found == s.size() - 1) {  // digits.
        return isDigits(s.substr(0, found)); 
      } else if (found == 0) {   // .digits
        return isDigits(s.substr(found + 1));
      } else {  // digits.digits
        return isDigits(s.substr(0, found)) && isDigits(s.substr(found + 1)); 
      }
    }

// ---- Everything is positive above ----

    bool isRealInt(string s) {
      if (s.empty()) return false;
      int start = 0;
      if (s[0] == '-' || s[0]  == '+') {
        start = 1;
      }
      return isInt(s.substr(start));
    }

    bool isRealFloat(string s) {
      if (s.empty()) return false;
      int start = 0;
      if (s[0] == '-' || s[0]  == '+') {
        start = 1;
      }
      return isFloat(s.substr(start));
    }

    // science = [real_float]['e'real_int]
    bool isScience(string s) {
      if (s.empty()) return false;
      size_t found = s.find("e");
      if (found == string::npos) {
        return isRealFloat(s);
      } else {
        return isRealFloat(s.substr(0, found)) && isRealInt(s.substr(found + 1));
      }
    }


    bool isNumber(string s) {
      // remove leading and trailing spaces
      int start = 0;
      while (s[start] == ' ') {
        start++;
      }
      int end = s.size() - 1;
      while (s[end] == ' ') {
        end--;
      }
      string f = s.substr(start, end - start + 1);
      return isScience(f);
    }
};

int main() {
  Solution sol;
  //cout << sol.isNumber("3.") << endl;
  //cout << sol.isNumber(".1") << endl;
  //cout << sol.isNumber("  0  ") << endl;
  //cout << sol.isNumber("G76") << endl;
  //cout << sol.isNumber("+.8") << endl;
  //cout << sol.isNumber("6e6.5") << endl;
  cout << sol.isNumber(" 005040476e+6") << endl;
}
