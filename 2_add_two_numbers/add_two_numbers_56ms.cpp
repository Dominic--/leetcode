/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        int l1_val = l1 ? l1->val : 0;
        l1 = l1->next;
        int l2_val = l2 ? l2->val : 0;
        l2 = l2->next;
        int tmp = l1_val + l2_val;
        int carry_bit = tmp / 10;
        
        struct ListNode * head = new ListNode(tmp % 10);
        struct ListNode * current = head;
        while (l1 || l2 || carry_bit) {
            l1_val = 0;
            l2_val = 0;
            
            if (l1) {
                l1_val = l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                l2_val = l2->val;
                l2 = l2->next;
            }
            
            tmp = l1_val + l2_val + carry_bit;
            carry_bit = tmp / 10;
            struct ListNode * next = new ListNode(tmp % 10);
            current->next = next;
            current = current->next;
        }
        
        return head;
    }
};