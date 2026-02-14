#include <iostream>
using namespace std;

int main() {

    int n, m, target;
    cin >> n >> m >> target;

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j= 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bool flag = false;

    //iterate through the columns first the rows for each column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == target) flag = true;
        }
    }

    cout << ((flag) ? "true" : "false");
}