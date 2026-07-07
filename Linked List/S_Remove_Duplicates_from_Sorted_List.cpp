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
    The list is sorted in non-decreasing order. Delete all duplicates so that
    each value appears only once, and return the head of the modified list.
*/

Node* deleteDuplicates(Node* head)
{
    // auto curr = head;
    // while (curr != NULL && curr -> next != NULL) {

    //     if (curr -> val == curr -> next -> val) {
    //         auto temp = curr -> next;
    //         curr -> next = curr -> next -> next;

    //         delete temp;

    //     } else {
    //         curr = curr -> next;
    //     }
    // }

    // return head;

    //using dummy node with a Val out of range 
    Node* dummy = new Node(-1e9);
    auto tail = dummy;

    //traverse
    auto ptr = head;
    while(ptr != NULL) {

        //first check then move ptr
        if (ptr -> val != tail -> val) {

            tail -> next = ptr;
            tail = ptr;
            ptr = ptr -> next;

        } else {

            //delete this node
            auto temp = ptr;
            ptr = ptr -> next; 
            delete temp; 

        }
    }

    tail -> next = NULL;

    //delete dummy 
    head = dummy -> next;
    delete dummy; 

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

    ll.head = deleteDuplicates(ll.head);

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