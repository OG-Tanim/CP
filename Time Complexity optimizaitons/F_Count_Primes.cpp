#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    int count = 0;
    // as n > 1; no need to check for 0, 1
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i != i) count += 2;
            else count ++;
        }
    }

    return (count == 2);
}

void solve() {
    int n;
    cin >> n;
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) count++;
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