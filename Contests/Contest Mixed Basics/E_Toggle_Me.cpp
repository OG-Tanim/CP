#include <iostream>
#include <vector>
using namespace std;

void solve() {
    string sIn, sOut = "";

    cin >> sIn;

    for (int i = 0; i < sIn.size(); i++) {
        if (sIn[i] >= 'a' & sIn[i] <='z') sOut += (sIn[i]) - 32;
        else sOut += sIn[i] + 32;
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