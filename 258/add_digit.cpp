// this is periodic with cycle = 9
// 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21
// 1  2  3  4  5  6  7  8  9  1  2  3  4  5  6  7  8  9  1  2  3
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return (num-1) % 9 + 1;
        
    }
};
