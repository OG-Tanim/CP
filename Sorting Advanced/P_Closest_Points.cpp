#include <bits/stdc++.h>
using namespace std;
#define int long long

// [{name, marks}, {name, marks}, {name, marks}]
struct Point {
    int x, y, dist;
};

bool comp(Point a, Point b) {

    //based on dist
    if (a.dist != b.dist) {
        return a.dist < b.dist;
    }

    //based on x
    if (a.x != b.x) {
        return a.x < b.x;
    }

    //based on y
    return a.y < b.y;

}


void solve() {

    int n, a, b; cin >> n >> a >> b; 
    vector<Point> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i].x;
        cin >> A[i].y;

        int distX = a - A[i].x, distY = b - A[i].y;

        A[i].dist = (distX * distX) + (distY * distY);
        
    }

    //Sort Descending using cusotm comparator
    sort(A.begin(), A.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << A[i].x << " " << A[i].y <<  '\n';
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