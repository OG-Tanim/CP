#include <iostream>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m];

    int arr3[m + n];

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {

        if (arr1[i] <= arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else {
            arr3[k] = arr2[j];
            j++;
            k++;
        }   
    }

    while (i < n) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    for (int i = 0; i < (m + n); i++) {
        cout << arr3[i] << " ";
    }
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}