#include <iostream>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;

    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        //swap with the previous element to avoid the loop from overflowing the array range - last element for even and 2nd last for odd will be the last iteration;
        for (int i = 1; i < n; i += 2) {
            swap(arr[i], arr[i - 1]);
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] <<((i == n - 1) ? "" : " ");
        }
        
        cout << endl;
    }
}