#include <bits/stdc++.h>
using namespace std;
#define int long long

void merge(vector<int> &A, int l, int r) {

    int mid = l + ((r - l) / 2);
    int i = l, j = mid + 1; 
    vector<int> temp;

    while (i <= mid && j <= r) {

        if (A[i] <= A[j]) {

            temp.push_back(A[i]);
            i++;

        }
        else {

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
}

void mergeSort(vector<int> &A, int l, int r) {

    //base case: only 1 element in the array
    if (l == r) return;

    //split in half
    int mid = l + ((r - l) / 2);

    //sort 1st Half
    mergeSort(A, l, mid);

    //sort 2nd half
    mergeSort(A, mid + 1, r);

    //merge
    merge(A, l, r);

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

    mergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}