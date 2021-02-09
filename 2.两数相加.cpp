/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root,*p;
        root = new ListNode();
        p = root;
        ListNode* p1,*p2;
        int adv = 0; // 进位
        p1 = l1;
        p2 = l2;
        while(p1 != nullptr || p2 != nullptr || adv){
            int num1 = p1 == nullptr?0:p1->val;
            int num2 = p2 == nullptr?0:p2->val;
            int num = num1 + num2 + adv;
            adv = num/10; // 重置进位
            
            p1 = p1 == nullptr?nullptr:p1->next;
            p2 = p2 == nullptr?nullptr:p2->next;
            
            p->val = num%10;
            if(p1 != nullptr || p2 != nullptr || adv)
                p->next = new ListNode();
            p=p->next;
        }
        return root;
    }
};
// @lc code=end

