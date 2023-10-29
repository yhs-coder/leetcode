/**
leetcode21. 合并两个有序链表
source: https://leetcode.cn/problems/merge-two-sorted-lists
**/

/********************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

example:
list1   1 2 null
list2   1 3 4 null
result:  1->1->2->3->4->null
*********************************************************************/
class Solution {
public:

#if 0
    // 方法二：递归
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /**
            list1   1 2 null
            list2   1 3 4 null
            第一次递归： merge(1,1);    list1->next = merge(2,1);    1->merge(2,1)
            第二次递归： merge(2,1);    list2->next = merge(2,3);    1->merge(2,3)
            第三次递归： merge(2,3);    list1->next = merge(null,3); 2->merge(null,3);
            回溯：return list2;     list1->next = list2;    2->3->4->null      
            回溯：return list1;     list2->next = list1;    1->2->3->4->null      
            回溯：return list2;     list1->next = list2;    1->1->2->3->4->null     
            return list1; 返回最终结果 
        **/
        // 终止条件：当两个链表都为空时，表示我们对链表已合并完成。
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        // 如何递归：我们判断 list1 和 list2 头结点哪个更小，然后较小结点的
        // next 指针指向其余结点的合并结果。（调用递归）
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
#endif
    // 迭代v2
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pHead = new ListNode(0);
        ListNode* prev = pHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        // 合并list1或list2中未被合并的节点
        prev->next = list1 == nullptr ? list2 : list1;
        prev = pHead->next;
        delete pHead;
        return prev;
    }
    /*
    // 方法一： 迭代 ,
    // 迭代v1(自己写的)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* cur3 = dummyHead;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                cur3->next = cur1;
                cur3 = cur3->next;
                cur1 = cur1->next;
            } else {
                cur3->next = cur2;
                cur3 = cur3->next;
                cur2 = cur2->next;
            }
        }
        // 其中一链表已遍历完
        if (cur1 == nullptr) {
            cur3->next = cur2;
        } else {
            cur3->next = cur1;
        }
        cur3 = dummyHead->next;
        delete dummyHead;
        return cur3;
    }
    */
};