/**
leetcode234. 回文链表
source: https://leetcode.cn/problems/palindrome-linked-list
**/

//如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
/**************************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **************************************************************************/
class Solution {
public:

    // 反转链表
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

    // 返回链表中间节点
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
     }
    bool isPalindrome(ListNode* head) {
        /**
            思路：首先找到链表中间节点，然后以该节点以起始，反转链表，最后再一一比较两链表
            注意: 不需要改变左边链表最后节点的next,如下边 2->3
            1 2 3 2 1                       1 2 2 1
            left    right                   left    right
            1 2     1 2->3->null            1  2    1   2->null
              2->3                          2->2        |        
        **/
        // 首先找到链表中间节点，然后以该节点以起始，反转链表，最后再一一比较两链表
        ListNode* mid = middleNode(head);
        ListNode* rightHead = reverseList(mid);

        ListNode* leftHead = head;
        while (leftHead && rightHead) {
            if (leftHead->val != rightHead->val) {
                return false;
            }
            leftHead = leftHead->next;
            rightHead = rightHead->next;
        }
        return true;
    }
    
};