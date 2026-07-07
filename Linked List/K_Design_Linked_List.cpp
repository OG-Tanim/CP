#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void build(int n) {
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* node = new Node(x);
            if (!head) head = tail = node;
            else tail->next = node, tail = node;
        }
    }

    void print() {
        bool first = true;
        Node* cur = head;
        while (cur) {
            if (!first) cout << ' ';
            cout << cur->val;
            first = false;
            cur = cur->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

/*
    Implement only the class below.
*/
class MyLinkedList {

private: 
    Node* head;
    Node* tail;
    int size;

    Node* getKthNode(int k) {

        if (k < 0 || k >= size) return nullptr;

        auto ptr = head; 
        for (int i = 0; i < k; i++) {
            ptr = ptr -> next; 
        }
        return ptr;
    }

public:
    MyLinkedList(Node* head) {
        // implement
        this -> head = head;
        this -> tail = nullptr;
        this -> size = 0; 

        auto ptr = head; 
        while (ptr != NULL) {
            tail = ptr; 
            size++; 
            ptr = ptr -> next;
        }

    }

    int get(int index) {
        // implement
        auto node = getKthNode(index);
        return node == nullptr ? -1 : node -> val;
    }

    void addAtHead(int val) {
        // implement
        auto newNode = new Node(val);

        newNode -> next = head;

        head = newNode; 
        size++;

        if (size == 1) tail = head; 
        
    }

    void addAtTail(int val) {
        // implement
        if (size == 0) {
            addAtHead(val);

        } else {
            auto newNode = new Node(val);

            tail -> next = newNode;

            tail = newNode;

            size++;
        }

    }

    void addAtIndex(int index, int val) {
        // implement
        if (index > size) return;

        if (index == size) {
            addAtTail(val);
            return;
        }

        if (index <= 0) {
            addAtHead(val);
            return;
        }

        auto prev = getKthNode(index - 1);

        auto newNode = new Node(val);

        newNode -> next = prev -> next;
        prev -> next = newNode; 
        size++;

    }

    void deleteAtIndex(int index) {
        // implement
        if (index < 0 || index >= size) return;

        Node* temp;

        if (index == 0) {

            temp = head; 
            head = head -> next;

            if (size == 1) tail = NULL;

        } else {

            auto prev = getKthNode(index - 1);
            temp = prev -> next;

            prev -> next = prev -> next -> next;

            if (index == size - 1) tail = prev;

        }

        delete temp;
        size--;

    }

    Node* getHead() {
        // implement
        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    MyLinkedList my(ll.head);

    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int index;
            cin >> index;
            cout << my.get(index) << "\n";
        } else if (type == 1) {
            int val;
            cin >> val;
            my.addAtHead(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            my.addAtTail(val);
        } else if (type == 3) {
            int index, val;
            cin >> index >> val;
            my.addAtIndex(index, val);
        } else {
            int index;
            cin >> index;
            my.deleteAtIndex(index);
        }
    }

    ll.head = my.getHead();
    ll.print();
    return 0;
}