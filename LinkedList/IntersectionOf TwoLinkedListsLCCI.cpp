/**
leetcode面试题 02.07. 链表相交
source: https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

**/

/*************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *************************************************************/
class Solution {
public:
    /**
    解题思路：
        前提：搞清题意，求的是相交的节点（地址相同），而不是两链表中相同的节点值
        首先，竟然两链表相交，其中相交后链表的长度，绝对不会长于两链表中的较短者。
        故先求出两链表的长度，然后移动较长链表，使其和短链表长度相同。
        然后再开始遍历链表，找出相交的节点返回，无则返回空
    **/

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int long_len = 0;
        int short_len = 0;
        // 假设headA为长链表
        ListNode* long_list = headA;
        ListNode* short_list = headB;
        ListNode* tmp_list = nullptr;

        // 求出链表的长度
        while (long_list != nullptr) {
            long_len++;
            long_list = long_list->next;
        }
        while (short_list != nullptr) {
            short_len++;
            short_list = short_list->next;
        }

        // 重置两链表
        long_list = headA;
        short_list = headB;

        // 如果headB为最长链表
        if (long_len < short_len) {
            tmp_list = long_list;
            long_list = short_list;
            short_list = tmp_list;
            // swap(long_list, short_list);
            int tmp = long_len;
            long_len = short_len;
            short_len = tmp;
            // swap(long_len, short_len);
        }

        // 求出链表长度差距，移动长链表，使其与短链表长度相同
        int gap = long_len - short_len;
        while (gap--) {
            long_list = long_list->next;
        }

        // 遍历两链表，找出两链表的相交点
        while (short_list != nullptr && long_list != nullptr) {
            if (short_list == long_list) {
                return short_list;
            }
            short_list = short_list->next;
            long_list = long_list->next;
        }
        return nullptr;
    }
};