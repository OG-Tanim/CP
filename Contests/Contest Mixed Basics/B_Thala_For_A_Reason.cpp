#include <iostream>
using namespace std;

void solve() {
    
    int n;
    cin >> n;

    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    } 

    cout << ((sum == 7) ? "Thala for a reason" : "Blocked for no reason") << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}