class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        x_ = x_center;
        y_ = y_center;
        r_ = radius;
    }
    
    vector<double> randPoint() {
        double r = sqrt(rand1()) * r_;
        double rad = rand1() * 2 * M_PI;
        return {r*cos(rad) + x_, r*sin(rad) + y_};
    }

    double rand1() {
        return static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    }
    
    double x_;
    double y_;
    double r_;
};

