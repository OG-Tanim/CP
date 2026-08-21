#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by two stacks).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

class MyQueue {

    stack<int> inStack, outStack; 
    int sz = 0; 

public:

    MyQueue()
    {

    }

    void push(int x)
    {
        inStack.push(x); 
        sz++; 
    }

    int pop()
    {   
        if (sz == 0) return -1;

        int elem = front(); 
        outStack.pop(); 
        sz--; 

        return elem;  
    }

    int front()
    {
        if (outStack.empty() && inStack.empty()) return -1; 

        if (outStack.empty()) 
        {
            while (!inStack.empty()) 
            {
                outStack.push(inStack.top()); 
                inStack.pop(); 
            }
        }

        return outStack.top(); 

    }

    int back()
    {
        if (sz == 0) return -1;

        if (inStack.empty()) 
        {   
            while (!outStack.empty()) {
                inStack.push(outStack.top()); 
                outStack.pop(); 
            }
        }

        return inStack.top();
    }

    bool empty()
    {
        return sz == 0;
    }

    int size()
    {
        return sz; 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyQueue que;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            que.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
            cout << que.pop() << '\n';
        else if (op == "front")
            cout << que.front() << '\n';
        else if (op == "back")
            cout << que.back() << '\n';
        else if (op == "empty")
            cout << (que.empty() ? "true" : "false") << '\n';
        else // size
            cout << que.size() << '\n';
    }

    return 0;
}