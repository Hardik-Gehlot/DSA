// https://practice.geeksforgeeks.org/problems/lru-cache/1
// Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and
// Q denotes the number of queries. Query can be of two types:

//     SET x y: sets the value of the key x with value y
//     GET x: gets the key of x if present else returns -1.

// The LRUCache class has two methods get() and set() which are defined as follows.

//     get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
//     set(key, value): if the key is already present, update its value. If not present, add the key-value
//     pair to the cache. If the cache reaches its capacity it should invalidate the least recently used
//     item before inserting the new item.
//     In the constructor of the class the capacity of the cache should be initialized.

// Example 1:

// Input:
// cap = 2
// Q = 2
// Queries = SET 1 2 GET 1
// Output: 2
// Explanation:
// Cache Size = 2

// SET 1 2 GET 1
// SET 1 2 : 1 -> 2

// GET 1 : Print the value corresponding
// to Key 1, ie 2.

// Example 2:

// Input:
// cap = 2
// Q = 8
// Queries = SET 1 2 SET 2 3 SET 1 5
// SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
// Output: 5 -1
// Explanation:
// Cache Size = 2
// SET 1 2 : 1 -> 2

// SET 2 3 : 1 -> 2, 2 -> 3 (the most recently
// used one is kept at the rightmost position)

// SET 1 5 : 2 -> 3, 1 -> 5

// SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence
// we delete the least recently used key-value pair)

// SET 6 7 : 4 -> 5, 6 -> 7

// GET 4 : Prints 5 (The cache now looks like
// 6 -> 7, 4->5)

// SET 1 2 : 4 -> 5, 1 -> 2
// (Cache size is 2, hence we delete the least
// recently used key-value pair)

// GET 3 : No key value pair having
// key = 3. Hence, -1 is printed.

// Your Task:
// You don't need to read input or print anything. Complete the constructor and get(), and set() methods
// of the class LRUcache.

// Expected Time Complexity: O(1) for both get() and set().
// Expected Auxiliary Space: O(1) for both get() and set().
// (Although, you may use extra space for cache storage and implementation purposes).

// Constraints:
// 1 <= cap <= 10^3
// 1 <= Q <= 10^5
// 1 <= x, y <= 10^4

struct Node
{
    int key, data;
    Node *next;
    Node *prev;

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class LRUCache
{
private:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int csize;
    unordered_map<int, Node *> pos;

    void addnode(Node *curr)
    {
        Node *temp = head->next;
        curr->next = temp;
        curr->prev = head;
        head->next = curr;
        temp->prev = curr;
    }

    void delnode(Node *curr)
    {
        Node *cprev = curr->prev;
        Node *cnext = curr->next;
        cprev->next = cnext;
        cnext->prev = cprev;
    }

public:
    // Initialization of capacity, head, tail.
    LRUCache(int cap)
    {
        csize = cap;
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        // If not present return -1.
        if (pos.find(key) == pos.end())
            return -1;

        Node *curr = pos[key];
        int val = curr->data;
        // Reposition Node
        delnode(curr);
        addnode(curr);
        // Update hashmap & return value.
        pos[key] = head->next;
        return val;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        // If already present delete node to insert in front.
        if (pos.find(key) != pos.end())
        {
            Node *curr = pos[key];
            delnode(curr);
        }
        // If cache is full delete last node.
        else if (pos.size() == csize)
        {
            pos.erase(tail->prev->key);
            delnode(tail->prev);
        }
        // Update the cache with the new key, value pair at front.
        Node *newnode = new Node(key, value);
        addnode(newnode);
        pos[key] = head->next;
    }
};