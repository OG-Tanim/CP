#include <bits/stdc++.h>
#include <map>
using namespace std;

void solve() {
    int n, target;
    cin >> n >> target;
    map<int, int>elemMap;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        int required = target - elem;  

        /*
        if the required value is already present in the map as key it means the required value is equal to another elem in the array(now set as key in the elemMap) that is not itself 
        */
        if (elemMap.count(required) != 0) {
            cout << elemMap[required] << " " << i + 1;
            return;
        }
        else {
            elemMap[elem] = i + 1;
        }
    }

    cout << -1 << endl;
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   