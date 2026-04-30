#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> A, B, C, D;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            bool d2 = (x % 2 == 0), d3 = (x % 3 == 0);
            if      (d2 && d3) A.push_back(x);
            else if (d2)       B.push_back(x);
            else if (d3)       C.push_back(x);
            else               D.push_back(x);
        }
        
        // Optimal order: [C][D][B][A]
        bool first = true;
        auto print = [&](vector<int>& v) {
            for (int x : v) {
                if (!first) cout << ' ';
                cout << x;
                first = false;
            }
        };
        print(C);
        print(D);
        print(B);
        print(A);
        cout << '\n';
    }
    return 0;
}