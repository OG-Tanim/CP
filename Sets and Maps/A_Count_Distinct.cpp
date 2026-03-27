#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int>st;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        st.insert(elem);
    }
    size_t size = st.size();
    cout << size;
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   