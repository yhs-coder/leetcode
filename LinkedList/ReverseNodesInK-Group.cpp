/**
leetcode25. K 个一组翻转链表
source: https://leetcode.cn/problems/reverse-nodes-in-k-group
**/

/*************************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *************************************************************************/
class Solution {
public:
    // 反转链表 双指针法 
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* rightNode = nullptr;
        ListNode* leftNode = nullptr;
        ListNode* pre = dummyHead;
        ListNode* succ = nullptr;
        int num = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            num++;
            // 处理待翻转链表左节点
            if (num % k == 1) {
                // 记录待翻转链表头节点的上一个节点
                leftNode = cur;
            }
            // 处理待翻转链表右节点
            if (num % k == 0) {
                rightNode = cur;
                succ = rightNode->next;
                rightNode->next = nullptr;
                // 链表拼接
                pre->next = reverseList(leftNode);
                leftNode->next = succ;

                // 迭代pre、num
                pre = leftNode;
                cur = leftNode;
            }
            cur = cur->next;
        }
        ListNode* tmp = dummyHead->next;
        delete dummyHead;
        return tmp;
    }
};