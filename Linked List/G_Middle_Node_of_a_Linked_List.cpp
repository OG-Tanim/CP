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
    Implement only the function below.
*/

int getLength(Node* head) {

    auto ptr = head; 
    int size = 0;
    while (ptr != NULL) {

        ptr = ptr -> next;
        size++;

    }
    return size; 

}

Node* findKthNode(Node* head, int k) {

    auto ptr = head; 

    for (int i = 1; i <= k - 1; i++) {
        ptr = ptr -> next;
    }

    return ptr; 
}

Node* findMiddle(Node* head) {

    // int length = getLength(head);

    // if (length % 2 != 0) {
    //     return findKthNode(head, length/2 + 1);
    // }
    // else return findKthNode(head, length/2);

    //SINGLE PASS
    auto slow = head;
    // auto fast = head;
    auto fast = head -> next;

    while (fast != nullptr && fast -> next != nullptr) {

        //move slow 1 step and fast 2 steps
        slow = slow -> next;
        fast = fast -> next -> next;  
    }
    return slow;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    Node* mid = findMiddle(ll.head);
    cout << mid->val << "\n";

    return 0;
}           