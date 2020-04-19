class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> res;
      int cand1 = -1, cand2 = -1, cnt1 = 0, cnt2 = 0;
      for (int x : nums) {
        if (cnt1 != 0 && cand1 == x) {
          cnt1++;
          continue;    
        }
        if (cnt2 != 0 && cand2 == x) {
          cnt2++;
          continue;
        }
        if (cnt1 == 0) {
          cand1 = x; cnt1 = 1;
          continue;
        }
        if (cnt2 == 0) {
          cand2 = x; cnt2 = 1;
          continue;
        }
        cnt1--; cnt2--;
      }
      int t1 = 0, t2 = 0;
      for (int x : nums) {
        if (x == cand1 && cnt1 != 0) {
          t1++;
        }
        if (x == cand2 && cnt2 != 0) {
          t2++;
        }
      }

      if (t1*3 > nums.size()) {
        res.push_back(cand1);
      }
      if (t2*3 > nums.size()) {
        res.push_back(cand2);
      }
      return res;
    }
};
