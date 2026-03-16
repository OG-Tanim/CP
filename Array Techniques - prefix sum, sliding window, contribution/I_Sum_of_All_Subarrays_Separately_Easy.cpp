#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {          //for the each element

        for (int j = i; j < n; j++) {      //for each subarray
            
            // [l = i, r = j] range of each subarray
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            cout << sum << endl;
        }
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
