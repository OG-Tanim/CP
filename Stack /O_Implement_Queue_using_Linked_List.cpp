#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by a singly linked list).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

class Node {
public:
    int val; 
    Node* next;

    Node(int v) {
        val = v; 
        next = NULL; 
    }
};

class LinkedList {

    Node* head = NULL; 
    Node* tail = NULL; 
    int _size = 0; 
    

public:
    void addAtTail(int val)
    {
        auto newNode = new Node(val);

        if (_size == 0) {
            head = newNode; 
        }
        else {
            tail -> next = newNode;  
        }

        tail = newNode;
        _size++; 
    }

    int deleteFromHead() 
    {
        if (_size == 0) return -1; 

        auto temp = head;
        int val = temp -> val;
        head = head -> next; 
        delete temp; 

        _size--; 
        if (head == NULL) tail = NULL; 
        return val; 
    }

    int getHead() 
    {
        return isEmpty() ? -1 : head -> val; 
    }

    int getTail()
    {
        return isEmpty() ? -1 : tail -> val;  
    }

    int size() 
    {   
        return _size; 
    }

    bool isEmpty() 
    {
        return _size == 0;
    }
};

class MyQueue {
    
    LinkedList ll; 
    
public:

    MyQueue()
    {

    }

    void push(int x)
    {
        ll.addAtTail(x);
    }

    int pop()
    {
        return ll.deleteFromHead();
    }

    int front()
    {
        return ll.getHead();     
    }

    int back()
    {
        return ll.getTail();   
    }

    bool empty()
    {
        return ll.isEmpty();   
    }

    int size()
    {
        return ll.size(); 
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