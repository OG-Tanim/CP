#include <bits/stdc++.h>
using namespace std;


/*
    Implement only the class below.
*/
class MinStack {

    //Basically track the min with element by each Pair <val, minSOFar>
    stack<pair<long long, long long >> st; 

public:
    MinStack() {
        // implement
    }

    void push(long long x) {
        // implement
        if (st.empty()) {
            st.push({x, x});
        }
        else {
            st.push({x, min(x, getMin())});
        }
    }

    void pop() {
        // implement
        if (st.empty()) return;
        st.pop();
    }

    long long top() {
        // implement
        if (st.empty()) return -1;
        return st.top().first;
    }

    long long getMin() {
        // implement
        if (st.empty()) return -1;
        return st.top().second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MinStack st;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            st.push(x);
        } else if (type == 2) {
            st.pop();
        } else if (type == 3) {
            cout << st.top() << "\n";
        } else {
            cout << st.getMin() << "\n";
        }
    }

    return 0;
}