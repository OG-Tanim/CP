#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> odd_pool, even_pool;
    long long total_sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        total_sum += val;
        if (i % 2 != 0) odd_pool.push_back(val);
        else even_pool.push_back(val);
    }
    
    int m_odd = 0, m_even = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x % 2 != 0) m_odd++;
        else m_even++;
    }
    
    auto get_marked_sum = [](vector<long long>& pool, int m_p) {
        if (m_p == 0 || pool.empty()) return 0LL;
        sort(pool.rbegin(), pool.rend());
        
        // We must mark the largest element at least once
        long long res = pool[0];
        int additional_marks = m_p - 1;
        
        // Mark remaining elements only if they are positive
        for (int i = 1; i < pool.size() && additional_marks > 0; ++i) {
            if (pool[i] > 0) {
                res += pool[i];
                additional_marks--;
            } else {
                break; // Further elements are <= 0
            }
        }
        return res;
    };
    
    long long marked_total = get_marked_sum(odd_pool, m_odd) + get_marked_sum(even_pool, m_even);
    cout << total_sum - marked_total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}