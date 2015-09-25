/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *pseudo = malloc(sizeof(struct ListNode));
    pseudo->next = head;
    
    struct ListNode *first = pseudo;
    // for second pointer will stop at the origin's previous node
    for (int i = 0; i < n + 1; i++) {
        first = first->next;
    }
    
    struct ListNode *second = pseudo;
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    struct ListNode *removed = second->next;
    second->next = second->next->next;
    free(removed);
    
    return pseudo->next;
}