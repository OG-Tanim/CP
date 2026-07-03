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
    Delete the middle node and return the head of the modified list.
    The middle node is the floor(n / 2)-th node (0-indexed).
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

Node* deleteMiddle(Node* node)
{   
    
    // int n = getLength(node); 

    // if (n < 2) {
    //     delete node; 
    //     return nullptr;
    // }

    // int mid = (n / 2) + 1;

    // auto ptr = node; 

    // //take ptr to the node just before mid
    // for (int i = 1; i <= mid - 2; i++) {
    //     ptr = ptr -> next; 
    // }

    // auto temp = ptr -> next; 

    // ptr -> next = ptr -> next -> next;

    // delete temp;

    //SLOW - FAST
    if (node == nullptr || node -> next == nullptr) {

        delete node; 
        return nullptr;

    }

    auto slow = node, fast = node, prev = node; 

    while (fast != nullptr && fast -> next != nullptr) {

        prev = slow; 
        slow = slow -> next; 
        fast = fast -> next -> next; 

    }
    //slow gives us 2nd mid in even numbers and prev the pointer just before it
    
    prev -> next = slow -> next;

    delete slow; 

    return node;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = deleteMiddle(ll.head);

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

