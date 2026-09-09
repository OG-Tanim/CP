#include <bits/stdc++.h>
using namespace std;

template<typename T>
using MinHeap = priority_queue<T, vector<T>, greater<int>>; 

/*
    Implement only the class below.
*/

class KthLargest {

    MinHeap<int> minHeap; 
    int k; 

public:

    KthLargest(int k, vector<int>& nums) {

        int n = nums.size(); 
        this -> k = k;

        for (int i = 0; i < n; i++) {
            minHeap.push(nums[i]); 

            if (minHeap.size() > k) {
                minHeap.pop(); 
            }
        }
    }

    int add(int val) {
        //append the value first
        minHeap.push(val); 

        if (minHeap.size() < k) return -1;

        if (minHeap.size() > k) {
            minHeap.pop(); 
        }

        return minHeap.top(); 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    KthLargest obj(k, nums);

    int q;
    cin >> q;

    while(q--)
    {
        int val;
        cin >> val;

        cout << obj.add(val) << '\n';
    }

    return 0;
}