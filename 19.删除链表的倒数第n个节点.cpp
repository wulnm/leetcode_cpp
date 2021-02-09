/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;
            // 快慢指针
        ListNode* behind, *cur;
        cur = head;
        for (int i = 0; i < n; i++)
        {
            cur = cur->next;
        }
        if(cur == nullptr){
            head = head->next;
            return head;
        }
        behind = head;
        while(cur->next != nullptr){
            behind = behind -> next;
            cur = cur->next;
        }
        behind->next=behind->next->next;
        return head;
    }
};
// @lc code=end

