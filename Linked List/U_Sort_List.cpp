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
    Sort the linked list in ascending order and return the new head.
*/
Node* getMiddleNode(Node* head) {
    
    auto slow = head;
    auto fast = head -> next; //we need the first mid in accordance with mid = (l + r) / 2 for even numbers

    //fast will either be the last node or the null 
    while (fast != NULL && fast -> next != NULL) {  
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node* mergeLinkedLists(Node* head1, Node* head2) {

    Node* dummy = new Node(-1);
    auto tail = dummy;

    auto ptr1 = head1;
    auto ptr2 = head2; 

    while (ptr1 != NULL && ptr2 != NULL) {

        if (ptr1 -> val <= ptr2 -> val) {
            //make the connection
            tail -> next = ptr1;
            //move tail to the that node
            tail = ptr1;
            //move ptr 
            ptr1 = ptr1 -> next;

        } else {

            tail -> next = ptr2; 
            tail = ptr2;
            ptr2 = ptr2 -> next;
            
        }
    }

    tail -> next = NULL;

    if (ptr1 != NULL) tail -> next = ptr1;
    if (ptr2 != NULL) tail -> next = ptr2;

    auto head = dummy -> next;
    delete dummy;

    return head;
}

Node* sortList(Node* head)
{
    //Merge Sort
    //base cases : when l > r or l == r
    if (head == NULL || head -> next == NULL) return head;

    auto mid = getMiddleNode(head);

    //start the linked lists
    auto head1 = head;
    auto head2 = mid -> next;
    
    //split them 
    mid -> next = NULL;

    //sort them using recursion
    head1 = sortList(head1);
    head2 = sortList(head2);

    //merge
    auto sortedHead = mergeLinkedLists(head1, head2);

    return sortedHead;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = sortList(ll.head);

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