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
    Partition the list so that every node with value < x comes before every
    node with value >= x, preserving the original relative order within each
    of the two partitions. Return the head of the partitioned list.
*/

Node* partition(Node* head, int x) {

    //create the dummy nodes and their tails for each group
    Node* dummy1 = new Node(-1);
    auto tail1 = dummy1;

    Node* dummy2 = new Node(-1);
    auto tail2 = dummy2;

    //traverse and update the tails
    auto curr = head;
    while (curr != NULL) {
        //do the checks first, then move to the next node
        if (curr -> val < x) {
            tail1 -> next = curr;
            tail1 = curr;

        } else {
            tail2 -> next = curr;
            tail2 = curr;
        }

        curr = curr -> next;
    }

    //complete the dummy groups 
    tail1 -> next = NULL;
    tail2 -> next = NULL;

    //connect the groups in order
    tail1 -> next = dummy2 -> next;
    
    //set head 
    head = dummy1 -> next;

    //delete the dummy nodes
    delete dummy1;
    delete dummy2;

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

    int x;
    cin >> x;

    ll.head = partition(ll.head, x);

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