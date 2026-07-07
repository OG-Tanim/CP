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
    Return the number of nodes in the loop, or 0 if there is no loop.
*/

int lengthOfLoop(Node* head) {

    auto fast = head; 
    auto slow = head;
    Node* meetingNode = NULL;

    while (fast != NULL && fast -> next != NULL) {

        slow = slow -> next;
        fast = fast -> next -> next; 

        if (fast == slow) {
            meetingNode = slow;
            break;
        }
    }

    if (meetingNode == NULL) {
        return 0; 
    }

    //slow comes to head and fast, slow move at the same speed
    slow = head;
    while (slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    //slow is the starting node of the cycle
    auto node = slow -> next;
    int cycleLength = 1;

    while (node != slow) {
        node = node -> next;
        cycleLength++;
    }

    return cycleLength;
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

    cout << lengthOfLoop(ll.head) << '\n';

    return 0;
}