#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = 0;
    vector<int> arrOut(n);


    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arrOut[index] = arr[i];
            index++;
        }
    }

    for (int i = index; i < n; i++) {
        arrOut[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << arrOut[i] << " ";
    }

    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}