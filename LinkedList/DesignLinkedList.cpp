/**	
	leetcode707. 设计链表
	source:https://leetcode.cn/problems/design-linked-list/
**/


class MyLinkedList {
public:
    // 链表节点
    struct LinkedNode {
        int _val;
        LinkedNode* next;
        LinkedNode(int val) : _val(val), next(nullptr){}
    };

    MyLinkedList() {
        _dummy_node = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        // 无效下标
        if (index < 0 || index > _size - 1) {
            return -1;
        }
        LinkedNode* cur = _dummy_node;
        while (index--) {
            cur = cur->next;
            // index--;
        }
        return cur->next->_val;
    }
    
    void addAtHead(int val) {
        LinkedNode* new_node = new LinkedNode(val); // 创建一个新节点
        LinkedNode* cur = _dummy_node;
        new_node->next = cur->next;
        cur->next = new_node;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* new_node = new LinkedNode(val); 
        LinkedNode* cur = _dummy_node;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        // 找到链表尾节点
        cur->next = new_node;
        _size++;
    }
    
    /*
        分情况：
        index 等于链表的长度，那么该节点会被追加到链表的末尾；
        index 大于链表的长度，return
        index  < 0 ,index = 0 ，头插
    */
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        // 头插
        if (index < 0) {
            index = 0;
        }
        LinkedNode* new_node = new LinkedNode(val); 
        LinkedNode* cur = _dummy_node;
        while (index--) {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index > _size - 1) {
            return;
        }
        LinkedNode* cur = _dummy_node;
        while (index--) {
            cur = cur->next;
        }
        // cur下一节点是要删除的节点
        LinkedNode* tmp = cur->next;    // 临时节点保存删除节点
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr; 
        _size--;
    }
    private:
        int _size;  // 链表长度
        LinkedNode* _dummy_node;  // 虚拟头节点
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */