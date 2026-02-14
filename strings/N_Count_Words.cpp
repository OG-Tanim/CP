#include <iostream>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        if ((char)s[i] == 32) count++;  
    }

    cout << count + 1;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}