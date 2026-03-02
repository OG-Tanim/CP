#include <iostream>
using namespace std;

void solve() {
    int n;
    long long diagonalSum = 0, nonDiagonalSum = 0;
    cin >> n;

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) diagonalSum += arr[i][j];
            else if (i != j & j == n - 1 - i) diagonalSum += arr[i][j];
            else nonDiagonalSum += arr[i][j];
        }
    }

    cout << diagonalSum << " " << nonDiagonalSum;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}