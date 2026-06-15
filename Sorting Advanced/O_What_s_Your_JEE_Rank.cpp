#include <bits/stdc++.h>
using namespace std;
#define int long long

// [{name, marks}, {name, marks}, {name, marks}]
struct Student {
    string name;
    int total;
    int physics;
    int chem;
    int maths;
};

bool comp (Student a, Student b) {

    //higher toal marks comes first when they are not equal
    if (a.total != b.total) {
        return a.total > b.total;
    }
    //higher maths marks comes first when they are not equal
    if (a.maths != b.maths) {
        return a.maths > b.maths;
    }

    //higher maths marks comes first when they are not equal
    if (a.physics != b.physics) {
        return a.physics > b.physics;
    }

    return a.name < b.name;
}

void solve() {

    int n; cin >> n; 
    vector<Student> A(n);

    for (int i = 0; i < n; i++) {

        cin >> A[i].name >> A[i].total >> A[i].physics >> A[i].chem >> A[i].maths;

    }

    int param = 3;
    //Sort 
    sort(A.begin(), A.end(), comp);

    for (int i = 0; i < n; i++) {

        cout << A[i].name << " " << A[i].total << " " << A[i].physics << " " << A[i].chem << " " << A[i].maths << '\n';

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