class Solution {
  public:
    int nthUglyNumber(int n) {
      vector<int> un;
      un.push_back(0); // dummy
      un.push_back(1);
      int p2 = 1, p3 = 1, p5 = 1;
      while (un.size() < n + 1) {
        int x = min(min(un[p2] * 2, un[p3] * 3), un[p5] * 5);
        un.push_back(x);
        if (x % 2 == 0) p2++;
        if (x % 3 == 0) p3++;
        if (x % 5 == 0) p5++;
      }


      return un[n];
    }
};
