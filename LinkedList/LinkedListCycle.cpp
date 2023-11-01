/**
leetcode141. 环形链表
source: https://leetcode.cn/problems/linked-list-cycle
**/

/****************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 ****************************************/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针法，每次快指针走两步，慢指针走一步
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};