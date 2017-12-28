#include <iostream>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

string add(const string& s1, const string& s2) {
    int n1 = s1.size(), n2 = s2.size();
    int n3 = max(n1, n2);
    string s3(n3, '0');
    int carry = 0;
    for (int i=n1-1,j=n2-1, k=n3-1 ; i>=0 || j>=0 ;i--,j--, k--) {
        int d1 = (i>=0 ? s1[i] - '0' : 0);
        int d2 = (j>=0 ? s2[j] - '0' : 0);
        int d3 = d1 + d2 + carry;
        carry = d3 / 10;
        d3 %= 10;
        s3[k] = d3 + '0';
    }
    if (carry == 0) {
        return s3;
    } else {
        return string(1, carry + '0') + s3;
    }
}

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        // try all (first, second) combination
        for (int n1=1; n1<=(n-1)/2; ++n1) {
            string s1 = num.substr(0, n1);
            for (int n2=1; n2<= min(n-2*n1, (n-n1)/2); ++n2) {
                int n3 = n-n1-n2;
                if (n1 > n3 || n2 > n3) break;  // n3 too small
                string s2 = num.substr(n1, n2);
                string s3 = num.substr(n1+n2);
                bool res = valid(s1, s2, s3);
                if (res) return true;
            }
        }
        return false;
    }

    bool valid(const string& s1, const string& s2, const string& s3) {
        if (s1.size() > 1 && s1[0] == '0') return false;
        if (s2.size() > 1 && s2[0] == '0') return false;

        if (s3.empty()) return true;

        string added = add(s1, s2);
        if (s3.size() < added.size()) return false;

        for (int i=0;i<added.size();++i) {
            if (s3[i] != added[i]) return false;
        }

        return valid(s2, added, s3.substr(added.size()));
    }

};

int main() {
    string m;
    cout << "number:";
    cin >> m;
    class Solution sol; 
    cout << sol.isAdditiveNumber(m) << endl;

}
