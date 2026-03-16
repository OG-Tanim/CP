#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    //pre sun arrray
    long long p[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {  
        long long elem;
        cin >> elem;
        sum += elem;
        p[i] = sum;
    }

    long long sumMax = p[k - 1]; // when L : i = 0, R : j = k - 1
    int i = 1, j = k;
    
    while (j < n) {                   
        long long sumSub = p[j] - p[i - 1]; 
        if (sumSub > sumMax) sumMax = sumSub;
        i++;
        j++;
    }

    cout << sumMax << endl;
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}