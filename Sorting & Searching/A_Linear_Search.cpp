#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t;
    cin >> t;

    string out = "NO";

    for (int i = 0; i < n; i++) {
        if (arr[i] == t) {
            out = "YES";
            break;
        } 
    }

    cout << out;
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}