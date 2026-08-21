#include <bits/stdc++.h>
using namespace std;
#define int long long

class MyCustomQueue {

    stack<pair<int, int>> inStack, outStack;  //{valeu, max}

    void pushHelper(stack<pair<int, int>> &st, int val) {

        if (st.empty()) {
            st.push({val, val});
        }
        else {
            st.push({val, max(val, st.top().second)});
        }

    }

public: 

    void push(int x) 
    {   
        pushHelper(inStack, x); 
    }

    void pop () 
    {
        if (outStack.empty()) {

            while(!inStack.empty()) {

                int elem = inStack.top().first;

                pushHelper(outStack, elem); 

                inStack.pop(); 
            }
        }

        outStack.pop(); 
    }

    int getMax()
    {
        if (outStack.empty()) return inStack.top().second;
        if (inStack.empty()) return outStack.top().second;

        return max(inStack.top().second, outStack.top().second); 
    }
};

void solve() {
    
    int n, k; cin >> n >> k; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans; 
    MyCustomQueue q; 
    for (int i = 0; i < k; i++) {
        q.push(a[i]); 
    }

    ans.push_back(q.getMax()); 
    for (int r = k; r < n; r++) {
        //l++
        q.pop(); 
        //r++
        q.push(a[r]);

        ans.push_back(q.getMax()); 
    }

    for (int x: ans) cout << x << " ";

    cout << endl; 
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