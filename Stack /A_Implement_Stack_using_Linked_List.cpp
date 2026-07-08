#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below, using a singly linked list.
    void push(int x) -- insert x onto the top of the stack.
    int  pop()       -- remove and return the top element; return -1 if empty.
    int  top()       -- return the top element; return -1 if empty.
    bool empty()     -- return true if the stack is empty, else false.
    int  size()      -- return the number of elements in the stack.
    Every operation must run in O(1) time.
*/

//Node Class
struct Node {
    int val;
    Node* next;

    Node(int val) {
        this -> val = val;
        this -> next = NULL; 
    }
};

class LinkedList {

    Node* head;
    int _size;

public:
    LinkedList() {
        head = NULL;
        _size = 0;
    }

    void addToHead(int val) {

        auto newNode = new Node(val);
        newNode -> next = head;
        head = newNode;

        _size++;
    }

    int deleteFromHead() {

        if (head == NULL) return -1;

        int ans = head -> val;
        auto temp = head;
        head = head -> next;

        delete temp;

        _size--;
        return ans;
    }

    int getHead() {
        if (head == NULL) return -1;

        return head -> val;
    }

    bool isEmpty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }
};

class MyStack {

    LinkedList list;

public:

    MyStack()
    {

    }

    void push(int x)
    {
        //for linked list - add to head
        list.addToHead(x); 
    }

    int pop()
    {
        //operation on head
        return list.deleteFromHead();
    }

    int top()
    {
        //return head val
        return list.getHead();
    }

    bool empty()
    {
        return list.isEmpty();
    }

    int size()
    {
        return list.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyStack st;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            st.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
        {
            cout << st.pop() << '\n';
        }
        else if (op == "top")
        {
            cout << st.top() << '\n';
        }
        else if (op == "empty")
        {
            cout << (st.empty() ? "true" : "false") << '\n';
        }
        else // size
        {
            cout << st.size() << '\n';
        }
    }

    return 0;
}