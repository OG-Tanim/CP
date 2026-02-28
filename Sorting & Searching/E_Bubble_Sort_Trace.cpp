#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {  //only need to place n - 1 (0 to n - 2) max elements at their respective last position

        int count = 0;
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                count++;
                swapped = true; 
            }
        }
        
        cout << "Pass " << i + 1 << ": ";
            
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << ", swaps = " << count << endl;

        if (!swapped) break;
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}