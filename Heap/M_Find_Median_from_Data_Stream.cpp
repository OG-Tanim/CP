#include <bits/stdc++.h>
using namespace std;

template <typename T>
using MaxHeap = priority_queue<T>; 

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>; 

/*
    Implement only the class below.
*/

class MedianFinder {

    MaxHeap<int> maxHeap; 
    MinHeap<int> minHeap; 
    int sz = 0;
    
    bool isBalanced() {
        return maxHeap.size() - minHeap.size() <= 1; 
    }

public:

    MedianFinder() {

    }

    void addNum(int num) {
        sz++; 

        maxHeap.push(num); 

        if (!isBalanced()) {

            minHeap.push(maxHeap.top()); 
            maxHeap.pop();

        }

        if (minHeap.size() > 0 and minHeap.top() < maxHeap.top()) {

            auto temp = maxHeap.top(); 
            maxHeap.pop();

            maxHeap.push(minHeap.top()); 
            minHeap.pop(); 

            minHeap.push(temp); 

        }
    }

    double findMedian() {

        if (sz == 0) return 0.0; 

        if (sz % 2 == 0) {
            return (maxHeap.top() + minHeap.top()) / (double)2; 
        }

        return maxHeap.top(); 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MedianFinder mf;

    cout << fixed << setprecision(5);

    while(Q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x;
            cin >> x;

            mf.addNum(x);
        }
        else
        {
            cout << mf.findMedian() << '\n';
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>

void solve() {
    
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