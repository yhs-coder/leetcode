/**
 * leetcode86. 分隔链表
 * source: https://leetcode.cn/problems/partition-list/
 * **/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // 创建两个链表，分别存 节点值<x  和 节点值>x 的所有节点，再进行拼接
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less_head = new ListNode(0);
        ListNode *greater_head = new ListNode(0);
        // 代码逻辑清晰！！！
        ListNode *less_tail = less_head;       // 小链表尾节点
        ListNode *greater_tail = greater_head; // 大链表尾节点
        ListNode *cur = head;
        // 遍历链表，将满足条件的节点分别插入大小链表中
        while (cur)
        {
            if (cur->val < x)
            {
                less_tail->next = cur;
                less_tail = less_tail->next;
            }
            else
            {
                greater_tail->next = cur;
                greater_tail = greater_tail->next;
            }
            cur = cur->next;
        }
        // 拼接两链表
        less_tail->next = greater_head->next;
        greater_tail->next = nullptr;
        ListNode *tmp_node = less_head->next;
        // 释放内存，避免内存泄漏
        delete less_head;
        delete greater_head;
        return tmp_node;
    }
#if 0 
    // 自己写的代码风格不够好！
    ListNode* partition(ListNode* head, int x) {
            // 新建两个链表
        ListNode* less_dummy = new ListNode(0);   // 存放节点值 < x 的所有节点
        ListNode* greater_dummy = new ListNode(0);     // // 存放节点值 > x 的所有节点
        ListNode* less = less_dummy;
        ListNode* greater = greater_dummy;
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        // 拼接两链表
        less->next = greater_dummy->next;
        greater->next = nullptr;
        ListNode* tmp = less_dummy->next;
        // 释放内存
        delete less_dummy;
        delete greater_dummy;
        return tmp;
    }
#endif
};