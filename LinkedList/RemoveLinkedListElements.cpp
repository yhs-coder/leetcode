/**
	leetcode203. 移除链表元素
	source: https://leetcode.cn/problems/remove-linked-list-elements/
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

    // 版本3.0 使用一个虚拟头结点，进行移除节点操作
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(0); // 设置一个虚拟头结点
        dummy_head->next = head;
        ListNode* current_node = dummy_head;    // 设置一个临时节点，替代虚拟节点操作
        // 优点：使用统一的删除节点逻辑
        while (current_node->next != nullptr) {
            if (current_node->next->val == val) {
                ListNode* tmp_node = current_node->next;
                current_node->next = current_node->next->next;
                delete tmp_node;
            } else {
                current_node = current_node->next;
            }
        }
        head = dummy_head->next;
        delete dummy_head;  // 释放动态分配的节点，防止内存泄漏
        return head;
}
    

#if 0
    // 版本2.0 使用原链表移除节点
     ListNode* removeElements(ListNode* head, int val) {
         ListNode* tmp_node = nullptr;
         // 删除满足条件的头节点
         // 用while的原因： 可能情况 [7,7,7,7] val = 7,需要循环释放
         while (head != nullptr && head->val == val) {
             tmp_node = head;
             head = head->next;
             delete tmp_node;   // 释放头节点，防止内存泄漏
         }

         // 删除非头节点
         ListNode* current_node = head;
         while ( current_node != NULL &&  current_node->next!= NULL) {
            if ( current_node->next->val == val) {
                ListNode* tmp =  current_node->next;
                 current_node->next =  current_node->next->next;
                delete tmp;
            } else {
                 current_node =  current_node->next;
            }
        }
        //  while (current_node != nullptr) {
        //      if (current_node->next != nullptr && current_node->next->val == val) {
        //         tmp_node = current_node->next;
        //         current_node->next = current_node->next->next;
        //         delete tmp_node;                 
        //      } else {
        //          current_node = current_node->next;
        //      }
        //  }
         return head;
    }
#endif

#if 0
    // 最初版本1.0
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev_node = nullptr;   // 前置节点
        ListNode* current_node = head;   // 当前节点
        ListNode* temp_node = nullptr;
        // 判断head是否为空
        if (head == nullptr) {
            return nullptr;
        }
        while (current_node) {
            // 找到节点
            if (current_node->val == val) {
                // 判断是否头删
                if (current_node == head) {
                    temp_node = head;
                    head = head->next;
                    current_node = head;
                    delete(temp_node);
                } else {
                    // 删除节点
                    temp_node = current_node;
                    current_node = current_node->next;
                    prev_node->next = current_node;
                    delete(temp_node);
                }
            } else {
                // 没找到节点
                // 移动current_node,prev_node到下一位置
                prev_node = current_node;
                if (current_node != nullptr) {
                    current_node = current_node->next;
                }
            }
        }
        return head;
    }
#endif

};