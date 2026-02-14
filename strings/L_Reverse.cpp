#include <iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int size = s.size();

    for (int i = 0; i < size / 2; i++) {
        swap(s[i], s[size - 1 - i]);       
    }

    cout << s;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}