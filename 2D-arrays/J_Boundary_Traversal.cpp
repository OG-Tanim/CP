#include <iostream>
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];            //taking input row(sub-array) by row
        }
    }

    if (n == 0 || m == 0) {
        return;
    }

        // Print Top Row
        for (int j = 0; j < m; j++) {
            cout << arr[0][j] << " ";
        }

        // last col : start from 2nd elem
        for (int i = 1; i < n; i++) {
            cout << arr[i][m - 1] << " ";
        }

        //Bottom Row - reverse : start from 2nd elem if not the same as Top Row
        if (n > 1) {
            for (int j = m - 2; j >= 0; j--) {
            cout << arr[n - 1][j] << " ";
        }
        }

        // first col - reverse : start from 2nd elem and finish before the last elem if not the same as last col
        if (m > 1) {
            for (int i = n - 2; i >= 1; i--) {
            cout << arr[i][0] << " "; 
        }
        }
}

int main() {

    int testCases = 1;
    // cin >> testCases;

    for (int i = 1; i <= testCases; i++) {
        solve();
    }

    return 0;
}