#include <bits/stdc++.h>
using namespace std;
#define int long long

// [{name, marks}, {name, marks}, {name, marks}]
struct Scholar {
    string name;
    int marks;
};

bool comp(Scholar a, Scholar b) {

    //higher marks comes first
    if (a.marks != b.marks) {
        return a.marks > b.marks;
    }

    return a.name < b.name;
}

void solve() {

    int n; cin >> n; 
    vector<Scholar> A(n);

    for (int i = 0; i < n; i++) {

        cin >> A[i].name;
        cin >> A[i].marks;

    }

    //Sort Descending using cusotm comparator
    sort(A.begin(), A.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << A[i].name << " " << A[i].marks << '\n';
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}  