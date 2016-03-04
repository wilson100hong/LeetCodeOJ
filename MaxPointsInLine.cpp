#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
  public:
    int gcd(int a, int b) {
      if (b == 0) return a;
      else return gcd(b, a % b);
    }

    int abs(int a) {
      return a < 0 ? -a : a;
    }

    string genKey(int dx, int dy) {
      return to_string(dx) + "$" + to_string(dy);
    }

    int maxPoints(vector<Point>& points) {
      int max = points.size() > 0 ? 1 : 0;
      for (int i = 0; i < points.size(); ++i) {
        unordered_map<string, int> hash_map;
        hash_map[genKey(0, 0)] = 1;
        for (int j = i + 1; j < points.size(); ++j) {
          int dx = points[i].x - points[j].x;
          int dy = points[i].y - points[j].y;
          int g = gcd(dx, dy);
          if (g != 0) {
            dx /= g;
            dy /= g;
          }
          //cout << key << endl;
          for (int k = 1; k >= -1; k-=2) {
            string key = genKey(dx*k, dy*k);
            if (hash_map.count(key) == 0) {
              hash_map[key] = 1;
            }
            hash_map[key]++;
            if (hash_map[key] > max) {
              max = hash_map[key];
            }
          }
        }
      }
      return max;
    }
};

int main() {
  Solution sol;
  vector<Point> points = {{0,0}, {-1,-1}, {2,2}};
  cout << sol.maxPoints(points) << endl;
}
