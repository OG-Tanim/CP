#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, target;
    cin >> n >> target;
    map<int, int>elemMap;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        int required = target - elem;

        /*
        if the required values is already present in the set it means the value is equal to another elem in the array(previously visited and now saved in the set) that is not itself 
        */
        if (elemMap.contains(required)) {
            count += elemMap[required];
        }
        if (elemMap.contains(elem)) {
            elemMap[elem]++;
        }
        else {
            elemMap[elem] = 1;
        }
    }

    cout << count << endl;
}

signed main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   