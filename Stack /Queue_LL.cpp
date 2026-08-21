#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    Node* tail = head; 
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

    void deleteFromHead() 
    {
        if (_size == 0) return; 

        auto temp = head;
        head = head -> next; 
        delete temp; 

        _size--; 
        if (head == NULL) tail = NULL; 
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


class Queue {

    LinkedList ll; 
  
public: 
    void push(int val) 
    {   
        ll.addAtTail(val); 
    }

    void pop() 
    {
        ll.deleteFromHead();
    }

    int front() 
    {
        return ll.getHead();
    }

    int back() 
    {
        return ll.getTail();
    }  

    int size() 
    {
        return ll.size();
    }

    bool empty()
    {
        return ll.size() == 0; 
    }
};
  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Queue q; 

    q.push(1); 
    // q.push(2);
    // q.push(3);
    // cout << q.front() << endl; 
    // cout << q.back() << endl; 
    
    // q.pop();
    // q.push(4);
    // q.push(5);
    // cout << q.front() << endl; 
    // cout << q.back() << endl; 
    // cout << q.size() << endl; 
    // cout << q.empty() << endl; 

    q.pop(); 
    cout << q.back() << endl; 

}