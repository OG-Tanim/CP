#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
    void push_front(int x) -- insert x at the front.
    void push_back(int x)  -- insert x at the back.
    int  pop_front()       -- remove and return the front element; -1 if empty.
    int  pop_back()        -- remove and return the back element; -1 if empty.
    int  front()           -- return the front element; -1 if empty.
    int  back()            -- return the back element; -1 if empty.
    bool empty()           -- return true if the deque is empty, else false.
    int  size()            -- return the number of elements.
    All operations must run in O(1).
*/

//double sided Node
class Node {

public: 
    int val; 
    Node* next; 
    Node* prev; 

    Node(int v) 
    {
        val = v; 
        next = NULL; 
        prev = NULL; 
    }

};

class DoublyLinkedList {

    Node* head = NULL; 
    Node* tail = NULL; 
    int sz = 0; 

public: 

    void addAtHead(int x) 
    {
        auto newNode = new Node(x); 

        if (head == NULL) {
            head = newNode; 
            tail = newNode; 
        }
        else 
        {
            newNode -> next = head; 
            head -> prev = newNode; 

            head = newNode;
        }
        sz++; 
    }

    void addAtTail (int x) 
    {   
        if (head == NULL) {
            addAtHead(x);  
            return; 
        }

        auto newNode = new Node(x); 

        tail -> next = newNode; 
        newNode -> prev = tail; 
        tail = newNode;
        sz++; 
    }

    int deleteFromHead() 
    {

        if (head == NULL) return -1; 

        auto temp = head;
        int value = temp -> val; 

        head = head -> next;  
        if (head != NULL) {
            head -> prev = NULL; 
        }
        else {
            tail = NULL; 
        }
        
        sz--; 
        delete temp; 
        return value; 
    }

    int deleteFromTail() 
    {

        if (head == NULL) return -1; 
        if (head == tail) 
        {
           return deleteFromHead(); 
        }

        auto temp = tail;
        int value = temp -> val; 
        
        tail = tail -> prev; 
        tail -> next = NULL; 
        sz--; 

        delete temp; 
        return value; 
    }

    int getHead() 
    {
        if (head == NULL) return -1; 

        return head -> val; 
    }

    int getTail () 
    {
        if (tail == NULL) return -1; 

        return tail -> val; 
    }

    bool isEmpty() 
    {
        return head == NULL; 
    }

    int getSize() 
    {
        return sz; 
    }

};

class MyDeque {

    DoublyLinkedList dll; 

public:

    MyDeque()
    {
    }

    void push_front(int x)
    {
        dll.addAtHead(x);
    }

    void push_back(int x)
    {
        dll.addAtTail(x);
    }

    int pop_front()
    {
        return dll.deleteFromHead();
    }

    int pop_back()
    {
        return dll.deleteFromTail();
    }

    int front()
    {
        return dll.getHead();
    }

    int back()
    {
        return dll.getTail(); 
    }

    bool empty()
    {
        return dll.isEmpty(); 
    }

    int size()
    {   
        return dll.getSize(); 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyDeque dq;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
            cout << "null" << '\n';
        }
        else if (op == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
            cout << "null" << '\n';
        }
        else if (op == "pop_front")
            cout << dq.pop_front() << '\n';
        else if (op == "pop_back")
            cout << dq.pop_back() << '\n';
        else if (op == "front")
            cout << dq.front() << '\n';
        else if (op == "back")
            cout << dq.back() << '\n';
        else if (op == "empty")
            cout << (dq.empty() ? "true" : "false") << '\n';
        else // size
            cout << dq.size() << '\n';
    }

    return 0;
}