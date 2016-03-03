#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

#define START 0
#define END 1

class Solution {
  public:
    int Dist(string w1, string w2) {
      int dist = 0;
      for (int i = 0; i < w1.size(); ++i) {
        if (w1[i] != w2[i]) dist++;
      }
      return dist;
    }

    void GetLineages(map<string, set<string>>& prevs, const string& w,
        vector<vector<string>>& result, vector<string>& current) {
      current.push_back(w);
      if (prevs.count(w) == 0 || prevs[w].size() == 0) {
        result.push_back(current);
        current.pop_back();
        return;
      }
      for (const string& p : prevs[w]) {
        GetLineages(prevs, p, result, current);
      }
      current.pop_back();
    }

    set<string> FindNeighbors(const unordered_set<string>& wordList, const string& word) {
      set<string> result;
      for (int i = 0; i < word.size(); ++i) {
        string newword = word;
        for (int j = 0; j < 26; ++j) {
          newword[i] = 'a' + j;
          if (word != newword && wordList.count(newword) != 0) {
            result.insert(newword);
          }
        }
      }
      return result;
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
      wordList.insert(beginWord);
      wordList.insert(endWord);
      if (beginWord == endWord) return { {beginWord} };

      set<string> queues[2];
      queues[START].insert(beginWord);
      queues[END].insert(endWord);

      map<string, int> depths[2];  // 0: depth from beginWord. 1: depth from endWord
      depths[START][beginWord] = 0;
      depths[END][endWord] = 0;

      map<string, set<string>> prevs[2];
      prevs[START][beginWord] = set<string>();
      prevs[END][endWord] = set<string>();

      vector<vector<string>> result;
      int current = START;
      // 2. BFS
      while (1) {
        set<string> tmp;
        if (queues[current].empty()) break;
        for (const string& u : queues[current]) {
          int depth = depths[current][u] + 1;
          set<string> neighbors = FindNeighbors(wordList, u);
          for (const string& v : neighbors) {
            if (depths[current].count(v) == 0 || depth <= depths[current][v]) {
              depths[current][v] = depth;
              if (prevs[current].count(v) == 0) {
                tmp.insert(v);
                prevs[current][v] = set<string>();
              }
              prevs[current][v].insert(u);
            }
          }
        }
        queues[current].clear();
        // do comparison to see if paths forms
        bool connected = false;
        int next = (current == START ? END : START);
        for (const string& w : tmp) {
          cout << "in tmp: " << w << endl;
          if (queues[next].count(w) != 0) {
            connected = true;
            // make path from prevs[current][w] and prevs[current][w]
            vector<vector<string>> befores, afters;
            vector<string> eb, ea;
            GetLineages(prevs[START], w, befores, eb);
            GetLineages(prevs[END], w, afters, ea);

            for (const vector<string>& after: afters) {
              for (const vector<string>& before: befores) {
                vector<string> path = after;
                for (int i = 1; i < before.size(); ++i) {
                  path.insert(path.begin(), before[i]);
                }
                result.push_back(path);
              }
            }
          }
          queues[current].insert(w);
        }
        if (connected) break
          break;
        current = next;
      }
      return result;
    }
};
