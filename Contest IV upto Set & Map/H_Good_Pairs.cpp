#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k, count = 0;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    
    map<int, int>freqMap;
    for (int i = 0; i < n; i++) {

        if (k == 0) {
            if (arr[i] == 0) {
                count += i;
            }
        }

        else if (arr[i] % k == 0) 
        {
            int req = arr[i] / k;
            count += freqMap[req];
        }
        
        freqMap[arr[i]] += 1;
    }

    cout << count << endl;
}

signed main()
{
    int t = 1;
    // cin >> t;

    while(t--)
    {
        solve();
    }
}
