#include <bits/stdc++.h>
using namespace std;
#define int long long

// [{name, marks}, {name, marks}, {name, marks}]
struct Flight {
    int flightNum, departureTime;
    string destination;
};

bool comp(Flight a, Flight b) {

    //based on departure time: earlier comes first
    if (a.departureTime != b.departureTime) {
        return a.departureTime < b.departureTime;
    }
    //based on flight Number
    return a.flightNum < b.flightNum;

}


void solve() {

    int n; cin >> n;
    vector<Flight> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i].flightNum >> A[i].departureTime >> A[i].destination;
    }

    //Sort Descending using cusotm comparator
    sort(A.begin(), A.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << A[i].flightNum << " " << A[i].departureTime << " " << A[i].destination << '\n';
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