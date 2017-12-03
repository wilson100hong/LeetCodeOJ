#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <iostream>

using namespace std;

class RandomizedCollection {
public:
    vector<pair<int, int>> nums;  // (val, offset in map-value)
    unordered_map<int, vector<int>> pos;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        pos[val].push_back(nums.size());
        nums.push_back({val, pos[val].size()-1});
        return pos[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (pos[val].size() == 0) {
            return false;
        }
        int index = pos[val].back();

        // replace with the last
        nums[index] = nums[nums.size()-1];

        // update pos map
        pos[nums[index].first][nums[index].second] = index;

        pos[val].pop_back();
        nums.pop_back(); 
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        //std::default_random_engine generator;
        //std::uniform_real_distribution<int> distribution(0, nums.size());
        //int index = distribution(generator);
        //return nums[index].first;
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
   RandomizedCollection rc; 
   rc.insert(1);
   rc.insert(1);
   rc.insert(2);
   cout <<rc.getRandom() << endl;
   rc.remove(1);
   cout << rc.getRandom() << endl;
   cout << rc.getRandom() << endl;
   cout << rc.getRandom() << endl;
   cout << rc.getRandom() << endl;
}
