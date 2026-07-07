#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void build(int n)
    {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            if(!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    Reverse the nodes from position left to right (1-indexed, inclusive)
    and return the head of the modified list.
*/

Node* reverseLinkedList(Node* head) {

    Node* prev = NULL;
    auto curr = head;

    while (curr != NULL) {
        auto next = curr -> next;

        curr -> next = prev;
        prev = curr;

        curr = next; 
    }

    return prev;
}

Node* reverseBetween(Node* head, int l, int r)
{
    if (l == r) return head; 
    
    auto ptr = head; 
    int idx = 1;
    
    Node* prevLeft = NULL; 
    Node* left = NULL; 
    Node* right = NULL; 
    Node* rightNext = NULL;
    
    while(ptr != NULL) {

        if (idx == l - 1) {
            prevLeft = ptr;
        }
        if (idx == l) {
            left = ptr;
        }
        if (idx == r) {
            right = ptr;
        }
        if (idx == r + 1) {
            rightNext = ptr;
        }

        ptr = ptr -> next;
        idx++;

    }

    //disconnect the reversal list 
    if (prevLeft != NULL) {
        prevLeft -> next = NULL;
    }
    right -> next = NULL;

    //reverse
    reverseLinkedList(left);

    //add the connections back
    left -> next = rightNext;

    if (prevLeft == NULL) {
        head = right;
    } else {
        prevLeft -> next = right;
    }

    return head;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int left, right;
    cin >> left >> right;

    ll.head = reverseBetween(ll.head, left, right);

    Node* cur = ll.head;

    bool first = true;

    while(cur)
    {
        if(!first)
        {
            cout << ' ';
        }

        first = false;

        cout << cur->val;

        cur = cur->next;
    }

    cout << '\n';

    return 0;
}