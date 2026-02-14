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

    //iterate through column first

    for (int j = 0; j < m; j++) {
        //print first to last for even cols and last to first for odd 
        if (j % 2 == 0) {

            // iterate through the rows for each col
            for (int i = 0; i < n; i++) {
            cout << arr[i][j] << " ";
        }
        }
        else {
            for (int i = n - 1; i >= 0; i--) {
            cout << arr[i][j] << " ";
        }
        }
    }
    
} 