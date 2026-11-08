class LFUCache {
private :

    struct DoubleListNode {
        int key;
        int val;
        int freq = 1;
        DoubleListNode * prev {};
        DoubleListNode * next {};
        DoubleListNode(int key, int val) : key(key), val(val) {};
    };

    int capacity = 0;
    DoubleListNode * head {};
    DoubleListNode * tail {};
    unordered_map<int, DoubleListNode *> cache {}; // key -> node
    unordered_map<int, DoubleListNode *> count {}; // freq -> first node of group with that frequency

    void detach(DoubleListNode * node)
    {
        if(node->prev) { node->prev->next = node->next;} else { head = node->next;}
        if(node->next) {  node->next->prev = node->prev; } else { tail = node->prev;}
        node->prev = node->next = nullptr;
    }

    void insertBefore(DoubleListNode * node, DoubleListNode * pos)
    {
        if(!pos)
        {
            // append after tail
            node->next = nullptr;
            node->prev = tail;
            if(tail)
            {
                tail->next = node;
            } else {
                head = node;
            }
            tail = node;
            return;
        }
        node->next = pos;
        node->prev = pos->prev;
        if(pos->prev)
        {
            pos->prev->next = node;
        } else {
            head = node;
        }
        pos->prev = node;
    }

    void toNextFrequency(DoubleListNode * node)
    {
        const int f = node->freq;
        auto it = count.find(f);
        bool wasFront = it->second == node;
        if(wasFront)
        {
            if(node->next && node->next->freq == f)
            {
                it->second = node->next;
            } else{
                count.erase(it);
            }
        }

        auto nextFreqIt = count.find(f + 1);
        if(nextFreqIt != count.end())
        {
            // f + 1 exist in count
            detach(node);
            insertBefore(node, nextFreqIt->second);
        } else if(!wasFront)
        {
            auto * pos = it->second;
            detach(node);
            insertBefore(node, pos);
        }

        node->freq = f + 1;
        count[f+1] = node;
    }

    void evict() {
        auto * victim = tail;
        auto it = count.find(victim->freq);
        if(it->second == victim)
        {
            count.erase(it);
        }
        detach(victim);
        cache.erase(victim->key);
        delete victim;
    }

public:

    LFUCache(int capacity) : capacity(capacity) {
        
    }

    ~LFUCache() {
        while(head)
        {
            auto * next = head->next;
            delete head;
            head = next;
        }
    }
    
    bool isFull()
    {
        return static_cast<int>(cache.size()) == capacity;
    }

    bool isEmpty()
    {
        return static_cast<int>(cache.size()) == 0;
    }

    int get(int key) {
        auto it = cache.find(key);
        if(it != cache.end())
        {
            toNextFrequency(it->second);
            return it->second->val;
        }   
        return -1;     
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end())
        {
            it->second->val = value;
            toNextFrequency(it->second);
        } else{
            auto * node = new DoubleListNode(key, value);
            if(isFull())
            {
                evict();
            }
            cache[key] = node;
            auto minFreqFrontIt = count.find(1);
            insertBefore(node, minFreqFrontIt != count.end() ? minFreqFrontIt->second : nullptr);
            count[1] = node;
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */