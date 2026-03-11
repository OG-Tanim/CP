#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    int count = 0;
    int limit = sqrt(n);      // (10 ^ 12)^.5 is within int limit

    for (int i = 1; i <= limit; i++) {

        if (n % i == 0) {
            if (n / i != i) count += 2;
            else count++;
        }
    }

    cout << count;
}

int main() {
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}