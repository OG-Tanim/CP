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
    Reorder the list in place from
        L0 -> L1 -> ... -> Ln-1
    to
        L0 -> Ln-1 -> L1 -> Ln-2 -> L2 -> ...
    Do not return anything; modify the list in place.
*/
Node* midNode(Node* head) {
    auto slow = head;
    auto fast = head -> next; //need the 1st mid of even nums 
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next; 
        fast = fast -> next -> next; 
    }
    return slow;
}

Node* reverseList(Node* head) {
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

void reorderList(Node* head)
{
    auto ptr1 = head;

    //mid node after which the nodes are reordered
    auto mid = midNode(head);

    //reverse the nodes after mid to get the order
    auto ptr2 = reverseList(mid -> next); 
    mid -> next = NULL;  //disconnect the lists now 

    //dummy to build the reordered list 
    // auto dummy = new Node(-1);
    // auto tail = dummy;
    // bool flip = true; 

    while (ptr2 != NULL) {
        // if (flip) {
        //     tail -> next = ptr1;
        //     tail = ptr1; 
        //     ptr1 = ptr1 -> next;
        // }
        // else {
        //     tail -> next = ptr2; 
        //     tail = ptr2;
        //     ptr2 = ptr2 -> next;
        // }
        // flip = !flip;

        //save the next nodes
        auto next1 = ptr1 -> next; 
        auto next2 = ptr2 -> next; 

        ptr1 -> next = ptr2;
        ptr2 -> next = next1; 

        ptr1 = next1; 
        ptr2 = next2; 

    }

    // if (ptr1 != NULL) tail -> next = mid;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    reorderList(ll.head);

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