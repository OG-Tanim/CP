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

    Node* getTail() {
        Node* cur = head;
        if (!cur) return nullptr;
        while (cur->next) cur = cur->next;
        return cur;
    }

    Node* getNodeAt(int idx) { // 0-indexed
        Node* cur = head;
        while (cur && idx--) cur = cur->next;
        return cur;
    }

    ~LinkedList() {
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

Node* getIntersectionNode(Node* headA, Node* headB) {

    // int a = getLength(headA);
    // int b = getLength(headB);

    // if (a < b) swap(headA, headB);
    // int diff = abs(a - b);

    // //forward headA
    // for (int i = 1; i <= diff; i++) {
    //     headA = headA -> next;
    // }

    // while (headA != headB) {
    //     headA = headA -> next;
    //     headB = headB -> next;
    // }

    // return headA;

    //Single Pass
    auto ptr1 = headA;
    auto ptr2 = headB;

    while (ptr1 != ptr2) {

        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next; 

        if (ptr1 == nullptr) ptr1 = headB;
        if (ptr2 == nullptr) ptr2 = headA;

    }

    return ptr1;

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nA, nB, common;
    cin >> nA >> nB >> common;

    LinkedList A, B, C;
    A.build(nA - common);
    B.build(nB - common);
    C.build(common);

    Node* commonHead = C.head;

    if (A.getTail()) A.getTail()->next = commonHead;
    else A.head = commonHead;

    if (B.getTail()) B.getTail()->next = commonHead;
    else B.head = commonHead;

    Node* ans = getIntersectionNode(A.head, B.head);

    if (ans == nullptr) cout << -1 << "\n";
    else cout << ans->val << "\n";

    return 0;
}