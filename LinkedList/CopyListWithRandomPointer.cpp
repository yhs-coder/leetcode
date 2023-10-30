/**
leetcode138. 随机链表的复制
source: https://leetcode.cn/problems/copy-list-with-random-pointer

**/


/*****************************
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*****************************/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. 创建拷贝节点，插入到原节点和其下一个节点之间
        Node* cur = head;
        Node* copy = nullptr;
        while (cur) {
            // 插入copy节点
            copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        
        // 2. 根据原节点的random，处理copy节点的random
        cur = head;
        while (cur) {
            copy = cur->next;
            // 判断cur->random是否为空
            if (cur->random == nullptr) {
                copy->random = nullptr;
            } else {
                // 根据插入的拷贝节点与原节点的前后链接关系，来处理拷贝节点的random
                copy->random = cur->random->next;
            }
            cur = copy->next;
        }

        // 3. 把拷贝节点从链表上解下来，链接成新链表，同时恢复原链表
        Node* copyHead = nullptr;
        Node* copyTail = nullptr;
        cur = head;
        while (cur) {
            copy = cur->next;
            // 恢复原链表
            cur->next = copy->next;
            // 将拷贝节点解下来，链接成新链表
            if (copyTail == nullptr) {
                copyHead = copyTail = copy;
            } else {
                copyTail->next = copy;
                copyTail = copy;
            }
            
            cur = cur->next;
        }
        return copyHead;

    }
};