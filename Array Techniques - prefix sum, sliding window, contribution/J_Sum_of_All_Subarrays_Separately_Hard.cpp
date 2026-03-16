#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long p[n];
    long long sum = 0;

    //prefix sum array
    for (int i = 0; i < n; i++) {
        long long elem;
        cin >> elem;
        sum += elem;
         p[i] = sum;
    }

    for (int i = 0; i < n; i++) {          //for the each element

        for (int j = i; j < n; j++) {      //for each subarray

            // [l = i, r = j] range of each subarray
            cout << ((i == 0) ? p[j] : (p[j] - p[i - 1])) << '\n';
        }
    }
}

int main() {
    //Fast I/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
