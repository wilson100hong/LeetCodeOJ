class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeight=0, maxIndex = -1;
        for (int i=0;i<height.size();++i)
            if (height[i] > maxHeight) {
                maxHeight = height[i];
                maxIndex = i;
            }
        
        int sum = 0, sofar = 0;
        for (int i=0;i<maxIndex;++i) {
            sofar = max(sofar, height[i]);
            sum += sofar - height[i];
        }
        
        sofar = 0;
        for (int i=height.size()-1;i>maxIndex;--i) {
            sofar = max(sofar, height[i]);
            sum += sofar - height[i];
        }
        return sum;
    }
};
