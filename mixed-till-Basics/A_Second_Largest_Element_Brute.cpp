#include <iostream>;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target = -1;

    //sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    int max = arr[n - 1];  //last elem is max

    //2nd largest distinct element
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] < max) {             //any elem that is smaller than max is checked if it is distinct
            bool distinct = true;

            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] == arr[i]) distinct = false;
                break;
            }

            if (distinct) {
                target = arr[i];
                break;
            }
        }
    }

    cout << target;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}