ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = NULL, *cur;
        
        int of = 0;
        while(l1 != NULL || l2 != NULL){
            int x = 0, y = 0;
            if(l1 != NULL){
                x = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                y = l2->val;
                l2 = l2->next;
            }
            
            x = x + y + of;
            of = x/10;
            x = x%10;
            
            if(head == NULL){
                head = new ListNode();
                head->val = x;
                cur = head;
            }
            else{
                cur->next = new ListNode();
                cur = cur->next;
                cur->val = x;
            }
            
            
        }
        if(of){
            cur->next = new ListNode();
            cur->next->val = of;
        }
        
        return head;
    }