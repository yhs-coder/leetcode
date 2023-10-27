/**
leetcode876. 链表的中间结点
source: https://leetcode.cn/problems/middle-of-the-linked-list/
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
    // 快慢指针法
    // 最终写法
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
     }

#if 0 
    // 使用数组进行存储
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> array = {head};
        while (array.back()->next != nullptr) {
            array.push_back(array.back()->next);
        }
        return array[array.size() / 2];
    }
#endif
    /* //自己的写法，使用虚拟头结点，写复杂冗余了
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* fast = dummy_head;
        ListNode* slow = dummy_head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

        }
        // 如果链表节点数为偶数，返回第二个中间节点
        if (fast != nullptr) {
            delete dummy_head;
            return slow->next;
        } else {
            // 链表节点数为奇数，返回中间节点
            delete dummy_head;
            return slow;
        }
    }
    */

};