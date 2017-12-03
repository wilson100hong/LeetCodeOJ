class Solution {
public:
    void rotate_string(vector<int>& s, int i, int j) {
        while (i<j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        rotate_string(nums, 0, n-k-1);
        rotate_string(nums, n-k, n-1);
        rotate_string(nums, 0, n-1);
    }
};
