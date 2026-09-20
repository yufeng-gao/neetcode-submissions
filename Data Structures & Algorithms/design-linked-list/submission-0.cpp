class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int val = 0, ListNode* next = nullptr, ListNode* prev = nullptr) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };

public:
ListNode* head;
ListNode* tail;
int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size || index < 0) return -1;
        else return getFromIndex(index)->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        if (size == 0) {
            head = new ListNode(val);
            tail = head;
            size++;
            return;
        }
        ListNode* newNode = new ListNode(val);
        if (index == size) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            size++;
            return;
        }
        if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            size++;
            return;
        }
        ListNode* idx = getFromIndex(index);
        ListNode* prev = idx->prev;
        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = idx;
        idx->prev = newNode;
        size++;
        return;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        ListNode* idx = getFromIndex(index);
        ListNode* prev = idx->prev;
        ListNode* next = idx->next;
        if (prev) {
            prev -> next = next;
        } else {
            head = next;
        }
        if (next) {
            next -> prev = prev;
        } else {
            tail = prev;
        }
        delete idx;
        size--;
    }
private:
    ListNode* getFromIndex(int index) {
        if (index > size / 2) {
            int offset = size - 1 - index;
            ListNode* curr = tail;
            for (int i = 0; i < offset; i++) {
                curr = curr->prev;
            }
            return curr;
        }
        else {
            ListNode* curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            return curr;
        }
    }
};