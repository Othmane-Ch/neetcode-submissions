struct DoubleListNode {
    int key {};    
    int val {};
    DoubleListNode * prev {};
    DoubleListNode * next {};
    DoubleListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {};
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
        return static_cast<int>(mp.size()) == 0;
    }

    bool isFull()
    {
        return static_cast<int>(mp.size()) == capacity;
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
        auto it = mp.find(key);
        if(it != mp.end())
        {
            res = it->second->val;
            detach(it->second);
            pushFront(it->second);
        }
        return res;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end())
        {
            it->second->val = value;
            detach(it->second);
            pushFront(it->second);
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
