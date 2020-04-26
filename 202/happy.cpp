class Solution {
  public:

    typedef unsigned long long ull;
    ull evolve(ull n) {
      ull x = 0;
      while (n > 0) {
        ull d = n % 10;
        x += (d*d);
        n /= 10;
      }
      return x;
    }


    bool isHappy(int n) {
      if (n == 1) return true;    
      ull slow = evolve(n), fast = evolve(slow);
      while (fast != slow) {
        slow = evolve(slow);
        fast = evolve(evolve(fast));
      }

      return fast == 1;
    }
};
