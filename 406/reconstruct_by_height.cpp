#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool ComparePeople(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

class Solution {
public:

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), ComparePeople);
        list<pair<int, int> > ll;
        for (const auto& person : people) {
            auto it = ll.begin();
            for (int i=0;i<person.second;++i) {
                it++;
            }
            ll.insert(it, person);
        }
        for (const auto& person : ll) {
            res.push_back(person);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<pair<int, int>> input = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<pair<int, int>> res = sol.reconstructQueue(input);
    for (const auto& person : res) {
        cout << person.first << " " << person.second << endl;
    }
}
