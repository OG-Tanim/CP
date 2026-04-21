#include <iostream>
using namespace std;

void solve() {
    int hour, minute;
    char delim;

    cin >> hour >> delim >> minute;

    cout << ((hour == minute) ? "Mogambo is happy" : "Mogambo is sad");
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}