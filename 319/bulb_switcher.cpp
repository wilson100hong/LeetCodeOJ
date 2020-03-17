// A bulb is off if its one-based index is a square of integer
class Solution {
public:
  int bulbSwitch(int n) {
    int i = 1;
    while (i*i <= n) {
      i++;
    }
    return i-1;
  }
};
