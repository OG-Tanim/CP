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
    Merge two sorted (non-decreasing) lists into one sorted list and return
    the head of the merged list. Either list may be empty (nullptr).
*/

Node* mergeTwoLists(Node* l1, Node* l2)
{
    Node* dummy = new Node(-1);
    auto tail = dummy;

    auto ptr1 = l1;
    auto ptr2 = l2;

    while (ptr1 != NULL && ptr2 != NULL) {

        if (ptr1 -> val <= ptr2 -> val) {

            tail -> next = ptr1;
            tail = ptr1;
            ptr1 = ptr1 -> next;

        } else {

            tail -> next = ptr2;
            tail = ptr2;
            ptr2 = ptr2 -> next;

        }
    }

    //check for remainder of either list
    if (ptr1 != NULL) tail -> next = ptr1;
    if (ptr2 != NULL) tail -> next = ptr2;

    auto head = dummy -> next;
    delete dummy;

    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1;
    cin >> n1;

    LinkedList a;
    a.build(n1);

    int n2;
    cin >> n2;

    LinkedList b;
    b.build(n2);

    Node* head = mergeTwoLists(a.head, b.head);

    Node* cur = head;

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