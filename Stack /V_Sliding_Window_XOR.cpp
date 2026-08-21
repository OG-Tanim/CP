#include <bits/stdc++.h>
using namespace std;
#define int long long

class MyCustomQueue {
    stack<pair<int, int>> inStack, outStack; //{val, XOR}

    void pushToStack(stack<pair<int, int>> &st, int val) 
    {
        if (st.empty()) {
            st.push({val, val});
        }
        else {
            st.push({val, (val ^ st.top().second)});
        }
    }

public: 
    void push(int val) {
        
        pushToStack(inStack, val); 
    }

    void pop() {

        if (outStack.empty()) {

            while (!inStack.empty()) {
                int curr = inStack.top().first; 
                inStack.pop(); 

                pushToStack(outStack, curr); 
            }
        }
        
        outStack.pop();
    }
    
    int getXOR() {

        if (inStack.empty()) return outStack.top().second; 
        if (outStack.empty()) return inStack.top().second; 
        return (inStack.top().second ^ outStack.top().second);
    }
};

void solve() {
    int n, k; cin >> n >> k; 
    vector<int> A(n); 
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i]; 
    }

    MyCustomQueue q; 

    for (int i = 0; i < k; i++) 
    {
        q.push(A[i]);
    }

    int ans = q.getXOR();

    for (int i = k; i < n; i++) 
    {
        q.push(A[i]); 
        q.pop();

        ans ^= q.getXOR(); 
    }

    cout << ans << endl; 
}  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}