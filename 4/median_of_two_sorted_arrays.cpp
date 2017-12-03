#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
    // kth is 1-based!, k > 0
    int findkth(vector<int>& a, int al, int ar,
                vector<int>& b, int bl, int br, int k) {
        int m = ar-al, n =br-bl;
        if (m > n) return findkth(b, bl, br, a, al, ar, k);

        // termination
        if (m==0) {
            return b[bl+k-1];
        }

        if (k==1) {
            return min(a[al], b[bl]);
        }

        int i = al + min(m, k/2);
        int j = bl+k/2;
        if (a[i-1] > b[j-1]) {
            return findkth(a, al, ar, b, j, br, k-(j-bl));
        } else {
            return findkth(a, i, ar, b, bl, br, k-(i-al));
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double s = static_cast<double>(findkth(nums1, 0, m, nums2, 0, n, (m+n+1)/2));
        double t = static_cast<double>(findkth(nums1, 0, m, nums2, 0, n, (m+n+2)/2));
        return (s+t)/2.0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
    cout << sol.findMedianSortedArrays(a, b) << endl;
    //cout << sol.findkth(a, 0, a.size(), b, 0, b.size(), 2) << endl;
    //cout << sol.findkth(a, 0, a.size(), b, 0, b.size(), 3) << endl;
    //cout << sol.findkth(a, 0, a.size(), b, 0, b.size(), 4) << endl;
    //cout << sol.findkth(a, 0, a.size(), b, 0, b.size(), 5) << endl;
}
