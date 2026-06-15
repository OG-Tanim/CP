#include <bits/stdc++.h>
using namespace std;
#define int long long

int merge(vector<int> &A, int l, int r) {

    int mid = l + ((r - l) / 2);
    int i = l, j = mid + 1;
    
    //Counting the reverse pairs in the 2 pairs
    int ans = 0;

    while (i <= mid && j <= r) {

        if (A[i] <= 2 * A[j]) {
            i++;
        }
        else {
            ans += mid - i + 1;
            j++;
        }
    }

    //Standaed Merge Sort
    vector<int> temp;
    i = l ; j = mid + 1;

    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
        } else {
            temp.push_back(A[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(A[i]);
        i++;
    }

    while (j <= r) {
        temp.push_back(A[j]);
        j++;
    }

    int ptr = 0;
    for (int i = l; i <= r; i++) {  

        A[i] = temp[ptr];
        ptr++; 

    }

    return ans;
}

int mergeSort(vector<int> &A, int l, int r) {

    //base case: only 1 element in the array
    if (l >= r) return 0;

    //split in half
    int mid = l + ((r - l) / 2);

    //REVERSE sort 1st Half and get the reverse pairs
    int ans1 = mergeSort(A, l, mid);

    //REVERSE sort 2nd half and get the reverse pairs
    int ans2 = mergeSort(A, mid + 1, r);

    //merge: reverse pairs between the 2 SORTED halves
    int ans3 = merge(A, l, r);

    return ans1 + ans2 + ans3;

}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    //cin >> t;
    // while (t--) solve();

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = mergeSort(A, 0, n - 1);

    cout << ans << endl;

}