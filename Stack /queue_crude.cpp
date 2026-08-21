#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_SIZE = 3; 

class Queue {
     
    int A[MAX_SIZE];
    int end = -1; 
    int start = -1;
    int _size = 0; 
  
public: 
    void push(int val) 
    {   
        if (_size == MAX_SIZE) return;

        //update the trackers
        if (empty()) {
            start = end = 0;
        }
        else {
            end = (end + 1) % MAX_SIZE; 
        }

        A[end] = val; 
        _size++; 
    }

    void pop() 
    {
        if (empty()) return; 
        //pops from the front
        start = (start + 1) % MAX_SIZE; 
        _size--; 
    }

    int front() 
    {
        return empty() ? -1 : A[start];
    }

    int back() 
    {
        return empty() ? -1 : A[end];
    }  

    int size() 
    {
        return _size;
    }

    bool empty()
    {
        return _size == 0; 
    }
};
  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Queue q; 

    q.push(1); 
    q.push(2);
    q.push(3);
    cout << q.front() << endl; 
    cout << q.back() << endl; 
    
    q.pop();
    q.push(4);
    q.push(5);
    cout << q.front() << endl; 
    cout << q.back() << endl; 
    cout << q.size() << endl; 
    cout << q.empty() << endl; 

}