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
    Node* tail;
    vector<Node*> nodes;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void build(int n)
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            nodes.push_back(node);

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
    Return the node where the cycle begins, or nullptr if there is no cycle.
*/

Node* detectCycle(Node* head)
{
    // set<Node*> addresses;
    // int idx = 0;

    // auto ptr = head;
    // while (ptr != NULL) {

    //     if (!addresses.contains(ptr)) {
    //         addresses.insert(ptr);

    //     } else {
    //         return ptr; 
    //     }

    //     ptr = ptr -> next;
    // }

    // return NULL;

    auto fast = head;
    auto slow = head;
    bool hasCycle = false;

    while (fast != NULL && fast -> next != NULL) {

        fast = fast -> next -> next;
        slow = slow -> next;

        if (fast == slow) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) {

        slow = head;

        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }

    } else {
        return NULL;
    }

    return slow;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int pos;
    cin >> pos;

    if(pos != -1)
        ll.tail->next = ll.nodes[pos];

    Node* ans = detectCycle(ll.head);

    int idx = -1;

    for(int i = 0; i < n; i++)
    {
        if(ll.nodes[i] == ans)
        {
            idx = i;
            break;
        }
    }

    cout << idx << '\n';

    return 0;
}