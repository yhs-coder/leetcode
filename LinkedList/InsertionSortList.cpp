/**
leetcode147. 对链表进行插入排序
source: https://leetcode.cn/problems/insertion-sort-list
**/

/*******************************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 ******************************************************************************/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head->next;
        ListNode* lastNode = head;
        while (cur != nullptr) {
            if (lastNode->val <= cur->val) {
                lastNode = cur;
            } else {
                ListNode* pre = dummyHead;
                while (pre->next->val <= cur->val) {
                    pre = pre->next;
                }
                lastNode->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = lastNode->next;
        }
        ListNode* tmp = dummyHead->next;
        delete dummyHead;
        return tmp; 

    }
};