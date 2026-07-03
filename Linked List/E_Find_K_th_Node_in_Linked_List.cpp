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
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
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
int findKth(Node* head, int k) {

    auto ptr = head;

    if (ptr == NULL) return -1;

    for (int i = 1; i <= k - 1; i++) {

        ptr = ptr -> next;

        if (ptr == NULL) return -1;

    }

    return ptr -> val;
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

    cout << findKth(ll.head, k) << "\n";

    return 0;
}