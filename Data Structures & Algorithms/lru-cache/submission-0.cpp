struct DoubleListNode {
    int key {};    
    int val {};
    DoubleListNode * prev {};
    DoubleListNode * next {};
    DoubleListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {};
    DoubleListNode(int val, DoubleListNode * prev, DoubleListNode * next) 
        : val(val), prev(prev), next(next) {};
};


class LRUCache {
private:
    int capacity = 0;
    DoubleListNode * head {};
    DoubleListNode * tail {};
    unordered_map<int, DoubleListNode *> mp {};
public:
    LRUCache(int capacity) : capacity(capacity) {}

    bool isEmpty()
    {
        return mp.size() == 0;
    }

    bool isFull()
    {
        return mp.size() == capacity;
    }

    void detach(DoubleListNode* node) {
        if (node->prev) 
        {
            node->prev->next = node->next;
        } else
        {
            head = node->next;
        }            
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        node->prev = node->next = nullptr;
    }

    void pushFront(DoubleListNode* node) {
        node->next = head;
        if(head) 
        {
            head->prev = node;
        }
        head = node;
        if (!tail) {
            tail = node;
        }
    }

    int get(int key) {
        int res = -1;
        if(mp.contains(key))
        {
            res = mp[key]->val;
            detach(mp[key]);
            pushFront(mp[key]);
        }
        return res;
    }

    void put(int key, int value) {
        if(mp.contains(key))
        {
            mp[key]->val = value;
            detach(mp[key]);
            pushFront(mp[key]);
        } 
        else 
        {
            if(isFull())
            {   
                mp.erase(tail->key);
                auto node = tail;
                detach(node);
                delete node;
            }
            DoubleListNode * node = new DoubleListNode(key, value);
            mp[key] = node;
            pushFront(node);
        }  
    }
};
