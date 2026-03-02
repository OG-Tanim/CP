#include <iostream>
using namespace std;

void solve() {
    
    string s;
    cin >> s;

    int countA = 0, countB = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            countA++;
        }
        else countB++;
    }

    cout << ((countA == countB) ? "YES" : "NO");
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}