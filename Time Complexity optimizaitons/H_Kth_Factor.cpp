#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
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

    int size = arr.size();
    //Bubble Sort
    for (int i = 0; i < size - 1; i++) {

        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    cout << ((size >= k) ? arr[k - 1] : -1); 
}

int main() {
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}