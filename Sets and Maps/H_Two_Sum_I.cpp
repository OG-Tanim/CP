#include <bits/stdc++.h>
#include <map>
using namespace std;

void solve() {
    int n, target;
    cin >> n >> target;
    set<int>elemSet;
    bool answer = false;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        int required = target - elem;  

        //if the required values is already present in the set it means the value is equal to another elem in the array that is not itself 
        if (elemSet.count(required) != 0) {
            answer = true;
            break;
        }
        else {
            elemSet.insert(elem);
        }
    }

    cout << ((answer) ? "TRUE" : "FALSE") << endl;
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   