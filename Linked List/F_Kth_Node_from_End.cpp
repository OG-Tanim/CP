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

Node* kthFromEnd(Node* head, int k) {

    //THE WHOLE THING IS 1 based indexed

    // int length = getLength(head);
    
    // auto ptr = findKthNode(head, length + 1 - k);

    // return ptr;

    //Single Pass
    auto slow = head, fast = head;

    //moving fast k steps away from slow
    for (int i = 1; i <= k; i++) {
        fast = fast -> next;
    }

    while (fast != NULL) {
        fast = fast -> next;
        slow = slow -> next;
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

    int k;
    cin >> k;

    Node* ans = kthFromEnd(ll.head, k);
    cout << ans->val << "\n";

    return 0;
}