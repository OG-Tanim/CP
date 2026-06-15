#include <bits/stdc++.h>
using namespace std;
#define int long long
 
// [{name, marks}, {name, marks}, {name, marks}]
struct Order {
    int id, timestamp, priority;
};
 
bool comp(Order a, Order b) {
 
    //based on priority: higher comes first
    if (a.priority != b.priority) {
        return a.priority > b.priority;
    }
 
    //based on timestamp: earlier comes first
    if (a.timestamp != b.timestamp) {
        return a.timestamp < b.timestamp;
    }
 
    //based on y
    return a.id < b.id;
 
}
 
 
void solve() {
 
    int n; cin >> n;
    vector<Order> A(n);
 
    for (int i = 0; i < n; i++) {
        cin >> A[i].id >> A[i].timestamp >> A[i].priority;
    }
 
    //Sort Descending using cusotm comparator
    sort(A.begin(), A.end(), comp);
 
    for (int i = 0; i < n; i++) {
        cout << A[i].id << " " << A[i].timestamp << " " << A[i].priority << '\n';
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