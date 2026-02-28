#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        int shifts = 0;

        for (int j = i; j > 0; j--) {

                if (arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j - 1]);
                    shifts++;
                }
                else break;
            }
            
        cout << "Pass " << i << ": ";

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << ", ";

        for (int k = 0; k <= i; k++) {
            cout << arr[k] << " ";
        }
        
        cout << "| ";

        for (int k = i + 1; k < n; k++) {
            cout << arr[k] << " ";
        }


        cout << ", shifts = " << shifts << endl;
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}