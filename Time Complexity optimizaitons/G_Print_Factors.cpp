#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long>arr;

    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i != i) {
                arr.push_back(i);
                arr.push_back(n / i);
            }
            else arr.push_back(i);
        }
    }

    //Bubble Sort
    for (int i = 0; i < arr.size() - 1; i++) {

        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}