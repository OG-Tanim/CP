#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
    LRUCache(int capacity) -- initialize the cache with the given capacity.
    int  get(int key)      -- return the value if present, else -1.
    void put(int key, int value) -- insert/update; evict the least recently
                                    used entry if the capacity is exceeded.
    Both get and put must run in O(1) average time.
*/

struct Node {
    pair<int, int> val; 
    Node *next; 
    Node *prev;
    
    Node(int key, int value) {
        this -> val = {key, value}; 
        this -> next = NULL;
        this -> prev = NULL;
    }
}; 

class LRUCache {

    int capacity; 
    Node *dummyHead;
    Node *dummyTail;  

    unordered_map<int, Node*> m; 

    void removeNode(Node* node) {

        auto nextNode = node -> next; 
        auto prevNode = node -> prev; 

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void insertAtTail(Node *node) {

        auto tailPrev = dummyTail -> prev;
        tailPrev -> next = node;  
        node -> prev = tailPrev; 

         
        node -> next = dummyTail;
        dummyTail -> prev = node;
    }

    void moveToTail(Node *node) {

        //remove from current position
        removeNode(node); 

        //move to Dummy Tail Prev
        insertAtTail(node); 
    }

public:

    LRUCache(int capacity)
    {
        this -> capacity = capacity; 
        this -> dummyHead = new Node(-1, -1);
        this -> dummyTail = new Node(-1, -1);

        dummyHead -> next = dummyTail;
        dummyTail -> prev = dummyHead; 
    }

    int get(int key)
    {
        if (!m.contains(key)) return -1; 

        auto node = m[key]; 
        moveToTail(node);

        return node -> val.second; 
    }

    void put(int key, int value)
    { 
        if (capacity == 0) return; 

        //key already exists -> update value and move the element to tail
        if (m.contains(key)) {
            
            auto node = m[key]; 
            moveToTail(node);

            //update value
            node -> val.second = value; 
            return; 
        }

        //new Key -> check capacity and evict LRU if full 
        if (ssize(m) == capacity) {

            //remove node from dummyHead next 
            auto lru = dummyHead -> next; 
            removeNode(lru); 
            
            //remove from map 
            int key = lru -> val.first; 
            m.erase(key); 
            delete lru; 
        }

        //insert new Node at tail 
        auto newNode = new Node(key, value); 

        insertAtTail(newNode); 

        //update map 
        m[key] = newNode; 

    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cap, q;
    cin >> cap >> q;

    LRUCache cache(cap);

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "get")
        {
            int k;
            cin >> k;
            cout << cache.get(k) << '\n';
        }
        else
        {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
            cout << "null" << '\n';
        }
    }

    return 0;
}