/**
leetcode142. 环形链表 II
source： https://leetcode.cn/problems/linked-list-cycle-ii/
**/

/************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 ************************************************************/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /**
            思路：
            1. 判断链表是否成环  --> 使用快慢指针
            2. 若成环，则找出环的入口节点   --> 利用快慢指针之间的关系，得出从链表头节点到环的节点数 等于 快慢指针交点处转n圈后，到环的入口节点数
        **/
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            // 每次快指针移动的节点数是慢指针的两倍
            fast = fast->next->next;
            slow = slow->next;
            // 如果快慢指针相遇，说明成环
            if (fast == slow) {
                ListNode* meet_node = fast;
                ListNode* start_node = head;    // 链表的头节点
                
                // 寻找环的入口节点
                while (meet_node != start_node) {
                    meet_node = meet_node->next;
                    start_node = start_node->next;
                }
                return start_node;  // 返回环的入口节点
            }
        }
        return nullptr; // 不成环
    }
};