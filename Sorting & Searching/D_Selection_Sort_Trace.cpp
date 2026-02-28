#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t;
    cin >> t;

    string out = ", min_selected = ";

    for (int i = 0; i < n - 1; i++) {
        int min = arr[i];
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);

        cout << "Pass " << i + 1 << ": ";

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << out << min << endl;
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}