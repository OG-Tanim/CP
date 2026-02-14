#include <iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int size = s.size();

    bool flag = true;


    for (int i = 0; i < size / 2; i++) {
        if (s[i] != s[size - 1 - i]) flag = false;  
    }

    cout << ((flag) ? "YES" : "NO");
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}