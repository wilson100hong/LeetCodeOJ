#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


unordered_map<string, string> rm;

string reduce(string s) {
    if (s.size() < 3) return s;

    if (rm.count(s) != 0) return rm[s];

    int cnt = 1;
    int pos = -1;
    for (int i=1;i<s.size();++i) {
        if (s[i] == s[i-1]) {
            cnt++;
            if (cnt >= 3) pos = i;
        } else if(cnt >= 3) {  // s[i] != s[i-1]
            break;
        } else {
            cnt = 1;
        }
    }

    if (pos == -1) {
        rm[s] = s;

    } else {
        rm[s] = reduce(s.erase(pos - cnt + 1, cnt));
    }

    return rm[s];
}

//string reduce(const string& str) {
    //if (str.size() < 3) return str;

    //string s(str);
    //int x;
    
    //do {
        //x = -1;
        //int cnt = 1;
        //for (int i=1;i<s.size();++i) {
            //if (s[i] == s[i-1]) {
                //cnt++;
                //if (cnt >= 3) x = i;
            //} else if(cnt >= 3) {
                //break;
            //} else {
                //cnt = 1;
            //}
        //}

        //if (x != -1) {
            //cout << "x: " << x << endl;
            //cout << "cnt: " << cnt << endl;
            //s.erase(x - cnt +1, cnt);
            //cout << "s: " << s << endl;
        //}
    //} while (x != -1);
    //return s;
//}

int main () {

    string board;
    cout << "board:";
    cin >> board;
    cout << board << endl;
    cout << reduce(board) << endl;
}
