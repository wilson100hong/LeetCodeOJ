class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      int cnt = 0, res = -1;
      for (int x : nums) {
        if (cnt == 0) {
          res = x;
          cnt = 1;
        } else {
          if (x == res) cnt++;
          else cnt--;
        }
      }
      return res;
    }
};
