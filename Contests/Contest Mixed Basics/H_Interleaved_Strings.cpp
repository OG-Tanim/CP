#include <iostream>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    string sOut = "";
    sOut += s[0];

    int i = 1, j = 0;

    while (i < s.size() || j < t.size()) {

        if (j < t.size()) {
            sOut += '-';
            sOut += t[j];
            j++;
        }
        if (i < s.size()) {
            sOut += '-';
            sOut += s[i];
            i++;
        }
    }

    cout << sOut;

}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}