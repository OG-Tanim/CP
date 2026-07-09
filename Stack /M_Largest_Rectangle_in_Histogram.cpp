#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> getNextLeftSmaller (vector<int> &A) {
    int n = A.size(); 
    stack<int> st;            //storing indexes
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {

        //remove useless elements (current is smaller than top so it can cover for any elem comes right to itself)
        while (!st.empty() && A[st.top()] >= A[i]) {
            st.pop();
        }
        //empty stack no smaller elem on the left
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top(); //index
        }

        //must push all elements even if current is bigger, it can be the next smallest for any element that comes after it to the right
        st.push(i);
    }

    return ans; 
}

vector<int> getNextRigtSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;                  //storing indexes
    vector<int> ans(n); 
    
    for (int i = n - 1; i >= 0; i--) {

        //relmove the useless elems (current just has to be smaller than top)
        while (!st.empty() && A[st.top()] >= A[i]) {    
            st.pop();
        }
        //empty : no elem to the right that's smaller - we use n for calclation of width
        if (st.empty()) {
            ans[i] = n; 
        }
        else {
            ans[i] = st.top(); //index
        }

        //bigger current than top can be next smaller for some elem to the left
        st.push(i);
    }

    return ans; 
}

void solve() {
 int n; cin >> n;
 vector<int> A(n);
 
 for (int i = 0; i < n; i++) {
    cin >> A[i];
 }

auto leftSmaller = getNextLeftSmaller(A); 
auto rightSmaller = getNextRigtSmaller(A);

 int ans = 0;
 for (int i = 0; i < n; i++) {

    int leftSmallerElementIndex = leftSmaller[i];
    int rightSmallerElementIndex = rightSmaller[i];

    int width = rightSmallerElementIndex - leftSmallerElementIndex - 1;
    int height = A[i];

    ans = max(ans, (width * height));
 }

 cout << ans << endl;

}  

// while (l >= 0 && A[l] >= A[i]) { 
//     len++;
//     l--;
// }
// while (r < n && A[r] >= A[i]) { 
//     len++;
//     r++;
// }

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}