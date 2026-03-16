#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long sum = 0;

    /* 
    Frequency Mehtod:
     by counting the number of times an element occurs in all the subarrays we can get the sum of all the 
     sums of all subarrays.

     for any element at index: 'i' (0 - indexed) comprises any the subarray [L, R] where:
     - the start index L is in the range [0, i] : (i + 1) possibilities
     - the end index R is in the range [i, n - 1] : (n - 1 - i + 1) = (n - i) possibilites.

     the total frequency of any elem[i] = (i + 1) * (n - i)
    */                                                                                     
    
    //each elem
    for (long long i = 0; i < n; i++) {
        long long elem;
        cin >> elem;

        sum += (elem * ((i + 1) * (n - i)));
    }

    cout << sum << endl;
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}