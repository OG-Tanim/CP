#include <bits/stdc++.h>
using namespace std;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main () {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < floor(n / 2); i++) {
        swap(arr[i], arr[n - 1 - i]);    
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}
