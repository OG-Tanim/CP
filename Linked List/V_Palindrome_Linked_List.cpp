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
    Return true if the linked list is a palindrome, otherwise false.
*/
Node* middleNode(Node* head) {

    auto slow = head;
    auto fast = head -> next; // need the first mid of an even num

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

bool isPalindrome(Node* head)
{
    auto mid = middleNode(head);

    auto head2 = reverseList(mid -> next);

    auto ptr1 = head;
    auto ptr2 = head2;

    while (ptr2 != NULL) {
        if (ptr1 -> val != ptr2 -> val) {
            return false;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    reverseList(head2);

    // while (head != NULL) {
    //     cout << head -> val;
    //     head = head -> next;
    // }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    cout << (isPalindrome(ll.head) ? "true" : "false") << '\n';

    return 0;
}