#include <iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int size = s.size();
    if (size != 10) {
        cout << "Weak";
        return;
    }

    string output = "Weak";
    bool hasLow = false;
    bool hasUp = false;
    bool hasDig = false;
    bool hasSp = false;

    for (int i = 0; i < size; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') hasLow = true;
        else if (s[i] >= 'A' && s[i] <= 'Z') hasUp = true;
        else if (s[i] >= '0' && s[i] <= '9') hasDig = true;
        else hasSp = true;
    }
     
    if (hasLow && hasUp && hasDig && hasSp) output = "Strong";

    cout << output;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}