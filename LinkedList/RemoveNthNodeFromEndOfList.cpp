/**
leetcode19. 删除链表的倒数第 N 个结点
source : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
**/

/**********************************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **********************************************************************************/
class Solution {
public:

    // 双指针法
    /*
        
        第一轮：
        dummy_head  1     2     3     4     5
        slow                   fast
        第二轮：  
        dummy_head  1     2     3     4     5
                  slow               fast 
        ...
        第四轮：  
        dummy_head  1     2     3     4     5
                              slow               fast 
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* slow = dummy_head;
        ListNode* fast = dummy_head;
        ListNode*tmp = nullptr; // 临时节点
        // 先让fast移动n个节点
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast = fast->next;  // 这样可以使得fats每次比slow多走三个节点，当fast为nullptr时，slow->next指向待删除节点，即slow为删除节点的上一个节点
        while (slow != nullptr && fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // 记得释放内存！！！
        tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        tmp = dummy_head->next;
        delete dummy_head;
        return tmp;
    }

#if 0 
    // 我的初始解法，冗余
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* cur = head;
        ListNode* dummy_head = new ListNode(0);
        ListNode* tmp = nullptr;
        dummy_head->next = head;
        // 得到节点数
        while (cur) {
            num++;
            cur = cur->next;
        }
        if (num == 0) {
            return nullptr;
        }
        cur = dummy_head;
        while (cur != nullptr && cur->next != nullptr) {            
            if (num == n) {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            num--;
            cur = cur->next;
        }
        tmp = dummy_head->next;
        delete dummy_head;
        return tmp;
    }
#endif
};