/**
leetcode61. 旋转链表
source: https://leetcode.cn/problems/rotate-list
**/
/****************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
****************************************************************/

class Solution {
public:
    // 前后指针法（比较繁琐）
    ListNode* rotateRight(ListNode* head, int k) {
        //  如果链表为空或者只有一个节点或k=0
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* newHead = head;
        ListNode* cur = head;
        int num = 0;
        while (cur) {
            num++;
            cur = cur->next;
        }
        int removeNum = num - k % num;
        if (removeNum == num) {
            return head;
        }
        while (removeNum--) {
            prev = newHead;
            newHead = newHead->next;
        }
        // 找到新链表的头节点
        cur = newHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        // 使得新链表的尾节点指向head
        cur->next = head;
        head = newHead;
        // 使新链表的尾节点为空
        prev->next = nullptr;
        return head;
    }
#if 0
    // 版本v2.0 通俗易懂,逻辑清晰
    ListNode* rotateRight(ListNode* head, int k) {
        //  如果链表为空或者只有一个节点或k=0
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* oldTail = head;
        int num = 1;
        while (oldTail->next != nullptr) {
            oldTail = oldTail->next;
            num++;
        }
        // 尾节点链接头节点，形成环形链表
        oldTail->next = head;

        // 找到新链表的尾节点
        ListNode* newTail = head;
        int removeNum = num - (k % num) - 1;
        while (removeNum--) {
            newTail = newTail->next;
        }
        // 新链表头节点
        head = newTail->next;
        //断开环形链表，即新尾节点指向空
        newTail->next = nullptr;
        return head;
    }
    #endif

    // 闭合成环 版本v1.0
    #if 0
    ListNode* rotateRight(ListNode* head, int k) {
        //  如果链表为空或者只有一个节点
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int num = 1;    // 链表节点数
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            num++;
        }
        // k是num的整数倍时，相当于没移动
        int remove = num - (k % num);
        if (remove == num) {
            return head;
        }

        // 找到尾节点,链接头节点，形成环
        tail->next = head;
        // 找到环中新链表头节点的前一节点，即新链表的尾节点，并在此处断开环
        while (remove--) {
            tail = tail->next;
        }

        // 断开环，使得尾节点指向空
        head = tail->next;
        tail->next = nullptr;
        return head;
        /*ListNode* tail = nullptr;
        while (k--) {
            ListNode* cur = head;
            ListNode* prev = nullptr;
            while (cur != nullptr && cur->next != nullptr) {
                prev = cur;
                cur = cur->next;
            }
            tail = cur;
            if (tail != nullptr) {
                tail->next = head;
                head = tail;
                prev->next = nullptr; 
            }

        }
        return head;*/
    }
    #endif
};