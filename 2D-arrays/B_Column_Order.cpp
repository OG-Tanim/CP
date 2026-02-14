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

    //iterate through the columns first the rows for each column
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << arr[i][j] << " ";
        }
    }
    
}