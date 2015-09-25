struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    
    struct ListNode *pseudo = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *res = pseudo;
    while (!(l1 == NULL && l2 == NULL)) {
        struct ListNode * tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        if (l1 == NULL) {
            tmp->val = l2->val;
            pseudo->next = tmp;
            
            l2 = l2->next;
        } else if (l2 == NULL) {
            tmp->val = l1->val;
            pseudo->next = tmp;
            
            l1 = l1->next;
        } else if (l1->val <= l2->val) {
            tmp->val = l1->val;
            pseudo->next = tmp;
            
            l1 = l1->next;
        } else if (l1->val > l2->val) {
            tmp->val = l2->val;
            pseudo->next = tmp;
            
            l2 = l2->next;
        }
        
        pseudo = pseudo->next;
    }
    
    return res->next;
}