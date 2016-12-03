#include <iostream>
#include <vector>
using namespace std;
// the idea is to separete the numbers in to two groups,
// and each group only has one distinct number.
// this can be done by using a non-zero bit in XOR result,
// where two distinct numbers must have different value on that bit.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) {
            x ^= n;
        }
        int offset = 0;
        while (1) {  // dont use while (x > 0) because x can be negative!
            if (x & 1) {
                break;
            }
            offset++;
            x = x >> 1;
        }

        int y = 0;
        for (int n : nums) {
            if ((n>>offset) & 1) {
                y ^= n;
            }
        }
        
        vector<int> res;
        res.push_back(y);
        for (int n : nums) {
            y ^= n;
        }
        res.push_back(y);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> input = {
       43772400,
       1674008457,1779561093,744132272,1674008457,448610617,1779561093,124075538,
       -1034600064,49040018,612881857,390719949,-359290212,-812493625,124732,-1361696369,
       49040018,-145417756,-812493625,2078552599,1568689850,865876872,865876872,-1471385435,1816352571,1793963758,2078552599,-1034600064,1475115274,-119634980,124732,661111294,-1813882010,1568689850,448610617,1347212898,-1293494866,612881857,661111294,-1361696369,1816352571,-1813882010,-359290212,1475115274,1793963758,1347212898,43772400,-1471385435,124075538,-1293494866,-119634980,390719949};
    vector<int> ans = sol.singleNumber(input);
    for (int a : ans) {
        cout << a << endl;
    }
}
