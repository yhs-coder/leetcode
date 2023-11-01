/**
leetcode92. 反转链表 II
source: https://leetcode.cn/problems/reverse-linked-list-ii

**/

/*********************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *********************************************************************/


class Solution {
public:
    // 版本v3 头插法
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* next = nullptr;
        
        // 1. 找到left的前一个节点
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;   // 每次迭代next
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        ListNode* tmp = dummyHead->next;
        delete dummyHead;
        return tmp;
    }
#if 0
    // 版本v2 使用虚拟头节点，逻辑清晰
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;  // 保存cur的下一节点
        ListNode* pre = nullptr;  // 前置节点
        ListNode* cur = head;
        while (cur) {  // 当前节点为空停止反转
            temp = cur->next;  
            // 反转核心逻辑
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre; 
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 头节点可能发生改变，并且处理起来有点麻烦，使用虚拟头节点来处理头节点
        ListNode* dummyNode = new ListNode(0);  // 创建虚拟头节点，用来指向头节点
        dummyNode->next = head;
        ListNode* pre = dummyNode;              // 保存left节点的前一个节点
        ListNode* leftNode = nullptr;           // 反转链表左节点
        ListNode* rightNode = nullptr;          // 反转链表右节点
        ListNode* succ = nullptr;               // 保存right节点的下个节点

        // 1. 找到链表中的pre和leftNode节点
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        leftNode = pre->next;

        // 2. 找到链表中的succ和rightNode节点
        // 从上面pre的位置继续查找
        rightNode = pre;
        for (int j = 0; j < right - left + 1; j ++) {
            rightNode = rightNode->next;
        }
        succ = rightNode->next;

        // 3. 将pre和rightNode后面的链接断开
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 3. 反转指定区域的链表, 并将pre的下一节点拼接到返回值
        pre->next = reverseList(leftNode);
        // 让反转后的尾节点拼接到succ
        leftNode->next = succ;

        // 释放内存
        ListNode* tmp = dummyNode->next;
        delete dummyNode;
        return tmp;
    }
#endif

#if 0
    // 版本v1: 我自己的粗糙写法
    ListNode* reverseList(ListNode* head) {
            ListNode* temp = nullptr;  // 保存cur的下一节点
            ListNode* prev = nullptr;  // 前置节点
            ListNode* cur = head;
            while (cur) {  // 当前节点为空停止反转
                temp = cur->next;  
                // 反转核心逻辑
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            return prev;   
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        int num = 1;    //  链表节点数
        ListNode* newHead = nullptr;    // 反转链表头节点
        ListNode* newTail = nullptr;    // 反转链表尾节点
        ListNode* prev = nullptr;       // 反转链表前一节点
        ListNode* tail = nullptr;       // 原链表尾节点
        ListNode* cur = head;    
        while (num < left) {
            prev = cur;
            cur = cur->next;
            num++;
        }  

        while (num <= right) {
            if (num == left) {
                newHead = cur;

            }
            if (num == right) {
                newTail = cur;
                tail = cur->next;
                newTail->next = nullptr;
            }
            cur = cur->next;
            num++;
        }

        // 反转选定的链表
        newHead = reverseList(newHead);
        newTail = newHead;
        while (newTail != nullptr && newTail->next != nullptr) {
            newTail = newTail->next;
        }
        newTail->next = tail;
        if (prev!= nullptr) {
            prev->next = newHead;
            return head;
        }else {
            return newHead;
        }
    }
#endif
};