/**
leetcode24. 两两交换链表中的节点
source: https://leetcode.cn/problems/swap-nodes-in-pairs/

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
 *******************************************************************************/

class Solution {
public:
    // 递归法
    /*
        1    2    3    4
      head   n2   n3
    */
     ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
        /*
        // 另一种写法
        ListNode* n3 = head->next->next;   
        ListNode* n2 = head->next;
        // 核心
        n2->next = head;    // 2-->1   4-->3
        head->next = swapPairs(n3); // 1-->3, 3-->null 传入下一个节点，重复操作
        return n2;  // 相邻节点交换完后的头结点，依次返回4  2
        */
    }
#if 0 
    // cur  1  2  3  4  null
    // cur --步骤一--> 2 --步骤二--> 1 --步骤3--> 3  4
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0); // 定义一个虚拟节点进行操作
        dummy_head->next = head;
        ListNode* cur = dummy_head;
        while (cur->next && cur->next->next) {
            
            ListNode* temp1 = cur->next;                // 记录第一个节点
            ListNode* temp2 = cur->next->next->next;    // 记录第二个节点
            
            cur->next = cur->next->next;    // 步骤一
            cur->next->next = temp1;        // 步骤二
            cur->next->next->next = temp2;  // 步骤三

            cur = temp1;    // cur移动两位，进行迭代（下一轮交换）
        }

        ListNode* temp3 = dummy_head->next; // 记录转换后链表头节点
        delete dummy_head;                  // 释放虚拟头节点，防止内存泄漏
        return temp3;        
    }
#endif

};