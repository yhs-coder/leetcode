/**
	leetcode206. 反转链表
	source: https://leetcode.cn/problems/reverse-linked-list/
**/

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
class Solution {
public:
    // // 版本3.1 递归法,从后往前翻转指针指向。
    ListNode* reverseList(ListNode* head) {
        // 边缘条件判断
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {    // 找到尾节点，回溯
            return head;
        }
        // 递归调用
        ListNode* last = reverseList(head->next);   // 传入下一节点
        // 返回尾节点后，从后往前进行翻转操作
        head->next->next = head;    // head为当前节点，操作其下一节点进行翻转
        head->next = nullptr;   // 使当前节点指向空
        return last;
    }

#if 0 
    // 版本3.0 递归法,从前往后翻转指针指向。
    ListNode* reverse(ListNode* prev, ListNode* cur) {
        if (cur == nullptr) {   // 终止条件
            return prev;
        }
        ListNode* temp = cur->next; // 保存cur的下一个节点
        cur->next = prev;
        return reverse(cur, temp);  // 传入cur当前节点和cur下一节点进行递归
        /*等价于
             prev = cur;
             cur = temp;
        */
        
    }
    ListNode* reverseList(ListNode* head) {
        // 整个链表反转，是循环让 cur节点的下一节点指向前置节点进行反转操作
        // 可使用递归进行反转操作
        return reverse(nullptr, head);
    }
#endif


#if 0
    // 版本2.0 双指针法 
     ListNode* reverseList(ListNode* head) {
         ListNode* temp = nullptr;  // 保存cur的下一节点
         ListNode* prev = nullptr;  // 前置节点
         ListNode* cur = head;
         while (cur) {  // 当前节点为空停止反转
             temp = cur->next;  
             // 反转核心逻辑
             cur->next = prev;
             prev = cur;
             cur = temp;
         }
         return prev;   
    }
#endif


#if 0 
    //版本1.0 普通做法
    ListNode* reverseList(ListNode* head) {
        /*n1  n2  n3
              1   2   3   4   5
        */
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* n1 = nullptr;
        ListNode* n2 = head;
        ListNode* n3 = head->next;
        while (n2) {
            n2->next = n1;  // 反转
            n1 = n2;
            n2 = n3;
            if (n3) {
                n3 = n3->next;
            }
        }
        return n1;
    }
#endif
};