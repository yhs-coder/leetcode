/**
 leetcode面试题 02.04. 分割链表
 source : https://leetcode.cn/problems/partition-list-lcci
 **/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // 创建两链表（大小），再进行拼接
    ListNode *partition(ListNode *head, int x)
    {
        // 新建两个链表
        ListNode *small_dummy = new ListNode(0); // 存放节点值 < x 的所有节点
        ListNode *big_dummy = new ListNode(0);   // // 存放节点值 > x 的所有节点
        ListNode *small = small_dummy;
        ListNode *big = big_dummy;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        // 拼接两链表
        small->next = big_dummy->next;
        big->next = nullptr;
        ListNode *tmp = small_dummy->next;
        // 释放内存
        delete small_dummy;
        delete big_dummy;
        return tmp;
    }

#if 0
    // 头插法
    ListNode* partition(ListNode* head, int x) {
        /**
            我的做法:头插法
            依次遍历，将小于x节点值的节点，依次头插，即插入到虚拟节点之后，最后再返回虚拟节点的next
        **/
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* cur = dummy_head;
        ListNode* tmp = nullptr;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val < x) {
                if (cur == dummy_head) {
                    cur = cur->next;
                } else {
                    tmp = cur->next;
                    cur->next = cur->next->next;
                    tmp->next = dummy_head->next;
                    dummy_head->next = tmp;
                }
            } else {
                cur = cur->next;
            }
        }
        tmp = dummy_head->next;
        delete dummy_head;
        return tmp;
    }
#endif
};