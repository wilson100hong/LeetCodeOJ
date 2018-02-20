// 
// Use i, j scanning
//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxWater = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            maxWater = max(h*(j-i), maxWater);
            while (i<j && height[i] <= h) i++;
            while (i<j && height[j] <= h) j--;
        }
        return maxWater;
    }
};
