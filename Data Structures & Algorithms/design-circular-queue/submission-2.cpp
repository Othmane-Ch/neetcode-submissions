struct ListNode {
    int val {};
    ListNode * next {};
    ListNode() = default;
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode * node) : val(val), next(node) {};
};

class MyCircularQueue {
private:
    int size = 0;
    int capacity = 0;
    ListNode * head {};
    ListNode * tail {};
public:
    MyCircularQueue(int k) : capacity(k) {}
    
    bool enQueue(int value) {
        ListNode * node = new ListNode(value, head);
        if(size == 0)
        {
            head = node; tail = node;
            tail->next = head;
            ++size;
            return true;
        }
        else if(size < capacity)
        {
            tail->next = node;
            tail = node;
            ++size;
            return true;
        }
        delete node;
        return false;
    }
    
    bool deQueue() {
        if(size > 0)
        {
            if(tail == head)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                auto * next = head->next;
                tail->next = next;
                delete head;
                head = next;
            }
            --size;
            return true;
        }
        return false;
    }
    
    int Front() {
        return head ? head->val : -1;
    }
    
    int Rear() {
        return tail ? tail->val : -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */