// 1. Binary Search termination (l > r)
// 2. slice (i, j) init
// 3. control flow in while loop 'continue'
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int max(int a, int b) {
      return a > b ? a : b;
    }
    int min(int a, int b) {
      return a < b ? a : b;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n1 = nums1.size(), n2 = nums2.size();
      if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
      }

      int l = 0, r = n1;
      int i = 0, j = (n1 + n2) / 2;
      while (l <= r) {
        i = (r + l) / 2;  // cut at nums1
        j = (n1 + n2) / 2 - i;
        if (i < n1 && j - 1 >= 0) {
          if (nums1[i] < nums2[j-1]) {
            // i too small 
            l = i + 1;
            continue;
          }
        }
        if (j < n2 && i - 1 >= 0) {
          if (nums2[j] < nums1[i-1]) {
            // i too large 
            r = i - 1;
            continue;
          } 
        }
        break;
      }
      //cout << "done" << endl;
      //cout << "i: " << i << ", j:" << j << endl;

      double right = 0.f;
      if (i >= n1) {
        right = nums2[j];
      } else if (j >= n2) {
        right = nums1[i];
      } else {
        right = min(nums1[i], nums2[j]);   
      }

      double left = 0.f;
      if (i < 1) {
        left = nums2[j-1];
      } else if (j < 1) {
        left = nums1[i-1];
      } else {
        left = max(nums1[i-1], nums2[j-1]);   
      }
      //cout << "L: " << left << ",R: " << right << endl;

      if ((n1 + n2) % 2 == 1) {
        return right;
      } else {
        return (left + right) / 2.0;
      }
    }
};

int main() {
  vector<int> m = {1, 4, 5};
  vector<int> n = {2, 3, 5};
  Solution sol;
  cout << sol.findMedianSortedArrays(m, n) << endl;
}
