#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j= 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        //print first to last for even rows and last to first for odd 
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
            cout << arr[i][j] << " ";
        }
        }
    }
    
} 