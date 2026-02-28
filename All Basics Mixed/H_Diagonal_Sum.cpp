#include <iostream>;
using namespace std;

void solve() { 
    int n, sum = 0;
    cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) sum += arr[i][j];
        }
    }

    cout << sum;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

}