#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> nextSmallerLeft(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n); 
    //next smaller elem on the left using stack
    stack<int> st; 
    for (int i = 0; i < n; i++) {
        int curr = A[i];
        //if curr is smalller, it can cover all elems that come after it 
        while (!st.empty() && A[st.top()] >= curr) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1; 
        }
        else {
            ans[i] = st.top();
        }

        //push ; even if curr is bigger it can be smaller to some next elem
        st.push(i);
    }

    return ans;
}

vector<int> nextSmallerRight(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n); 
    //next smaller elem on the right using stack
    stack<int> st; 
    for (int i = n - 1; i >= 0; i--) {
        int curr = A[i];
        //if curr is smalller, it can cover all elems that come before it 
        while (!st.empty() && A[st.top()] >= curr) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = n; 
        }
        else {
            ans[i] = st.top();
        }

        //push ; even if curr is bigger it can be smaller to some prev elem 
        st.push(i);
    }

    return ans;
}

int biggestSquareHistogram(vector<int> &A) {
    //leftsmaller, rightSmaller index arary 
    auto leftSmaller = nextSmallerLeft(A); 
    auto rightSmaller = nextSmallerRight(A);  
    int area = 0, n = A.size();

    for (int i = 0; i < n; i++) {
        int h = A[i];
        int w = rightSmaller[i] - leftSmaller[i] - 1; 

        area = max(area, h * w);
    }

    return area; 
}

void solve() {
    int n, m; 
    cin >> n >> m; 
    vector<vector<char>> A(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // Declare the histogram array 
    vector<int> row(m, 0); 
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 2. Update the histogram based on the current cell
            if (A[i][j] == '1') {
                row[j] += 1; // Accumulate on top of the previous row's height
            } else {
                row[j] = 0;  // Broken chain, reset height to 0
            }
        }

        //pass the current row into the biggest sqaure in Histogram 
        int area = biggestSquareHistogram(row);
        ans = max(ans, area);
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
    return 0;
}