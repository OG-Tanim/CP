#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string t;
    cin >> t;

    string out = "NO";

    int l = 0;
    int r = n - 1;

    while (l <= r) {          //l, r both can be equal to mid
        int mid = (l + r) / 2;

        if (arr[mid] == t) {  //arr[mid] > t : mid should include t but mid - 1 skips the [mid] checking
            out = "YES";
            break;
        }

        if (arr[mid] > t) {
            r = mid - 1;

        } else {
            l = mid + 1;
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