#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    //each sub-array is a range. so we can take prefix sum array
    long long p[n];
    long long sum = 0;

    for (int i = 0; i < n; i ++) {
        long long elem;
        cin >> elem;
        sum += elem;
        p[i] = sum;
    }

    long long ans = 0;
    //each elem
    for (int i = 0; i < n; i++) {
        //each subarray
        for (int j = i; j < n; j++) {
            //each subarray range : [l: i, r: j]
            if (i == 0) ans += p[j];
            else        ans += p[j] - p[i - 1];
        }
    }

    cout << ans;
}

int main() {
    //Fast I/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
