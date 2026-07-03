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

    ~LinkedList()
    {
        Node* cur = head;

        while(cur)
        {
            Node* nxt = cur->next;

            delete cur;

            cur = nxt;
        }
    }
};

/*
    Implement only the function below.
*/

void deleteNode(Node* node)
{
    auto temp = node -> next; //save the next node

    //convert current node into next node 
    node -> val = temp -> val; 
    node -> next = node -> next -> next;  //now the next node is out of the linked list

    //delete the next node
    delete temp;

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

    Node* cur = ll.head;

    while(pos--)
    {
        cur = cur->next;
    }

    deleteNode(cur);

    cur = ll.head;

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