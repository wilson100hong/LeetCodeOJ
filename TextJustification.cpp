// 1. paddig trailing spaces at last line.
// 2. padding spaces for single word line.
// 3. maxWidth == 0, words = []
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    string PaddingLine(vector<string>& words, int maxWidth, int remains) {
      int holes = words.size() - 1;
      string line = words.front();
      // add spaces

      for (int i = 1; i < words.size(); ++i) {
        int spaces = 1 + (remains / holes);
        if (remains % holes != 0) {
          spaces++;
          remains--;
        }
        for (int s = 0; s < spaces; ++s) {
          line = line + " ";
        }
        line = line + words[i];
      }
      while (line.size() < maxWidth) {
        line = line + " ";
      }
      return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> result;
      vector<string> currentLine;
      int currentWidth = 0;
      while (words.size() > 0) {
        int space = currentLine.empty() ? 0: 1;
        string word = words.front();
        if (!space && word.size() > maxWidth) {
          cout << "#1" << endl;
          string w1 = word.substr(0, maxWidth);
          string w2 = word.substr(maxWidth);
          words.erase(words.begin());
          words.insert(words.begin(), w2);
          words.insert(words.begin(), w1);
          continue;
        }
        int newWidth = currentWidth + space + word.size();
        if (newWidth <= maxWidth) {
          currentLine.push_back(word);
          words.erase(words.begin());
          currentWidth = newWidth;
        }
        if (newWidth >= maxWidth) {
          int remains = maxWidth - currentWidth;
          string line = PaddingLine(currentLine, maxWidth, remains);
          result.push_back(line);
          // reset
          currentWidth = 0;
          currentLine.clear();
        }
      }
      // handling last currentLine.
      if (currentLine.size() > 0) {
        string line = PaddingLine(currentLine, maxWidth, 0);
        result.push_back(line);
      }
      return result;
    }
};

int main() {
  Solution sol;
  //vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  vector<string> words = {""};
  vector<string> result = sol.fullJustify(words, 0);
  for (const string& str : result) {
    cout << str << endl;
  }
}
