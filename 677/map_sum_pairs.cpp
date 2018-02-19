// 2018/2/18
//
// TRAP 1: Trie node can be a word itself
// TRAP 2: always initalize your object
//
#include <iostream>
using namespace std;

class Trie {
public:
    Trie* children[26];
    int v;
    int s;

    Trie() {
        v = 0;
        s = 0;
        for (int i=0;i<26;++i) children[i] = nullptr;
    }

    // return delta
    int insert(string key, int val) {
        if (key.empty()) {
            int delta = val - v;
            v = val;
            s += delta;
            return delta;
        }

        int i = static_cast<int>(key[0] - 'a');
        if (children[i] == nullptr) {
            children[i] = new Trie();
        }
        int delta = children[i]->insert(key.substr(1), val);
        s += delta;
        return delta;
    }
    
    int sum(string key) {
        if (key.empty()) {
            return s;
        }
        int i = static_cast<int>(key[0] - 'a');
        if (children[i] == nullptr) return 0;
        return children[i]->sum(key.substr(1));
    }
};

class MapSum {
public:
    Trie* trie;
    /** Initialize your data structure here. */
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        trie.insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.sum(prefix);
    }
};


int main() {
    MapSum obj;
    cout << obj.sum("") << endl;
    obj.insert("apple", 3);
    cout << obj.sum("apple") << endl;
    obj.insert("app", 2);
    cout << obj.sum("ap") << endl;

}
