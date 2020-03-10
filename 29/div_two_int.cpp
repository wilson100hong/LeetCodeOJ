#include <iostream>

using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
      if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;  // overflow
      }

      bool neg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);

      long a = static_cast<long>(dividend);
      if (a < 0) a = -a;

      long b = static_cast<long>(divisor);
      if (b < 0) b = -b;
      
      long base = 1;
      while ((b << 1) <= a) {
        b = b << 1;
        base = base << 1;
      }

      long q = 0;
      while (b > 0) {
        if (a >= b) {
          a -= b;
          q += base;
        }
        base = base >> 1;
        b = b >> 1;
      }


      return neg ? -q : q;
    }
};

int main() {
  Solution sol;
  //cout << sol.divide(10, 3) << endl;
  //cout << sol.divide(7, -3) << endl;
  cout << sol.divide(-2147483648, 1) << endl;
}

