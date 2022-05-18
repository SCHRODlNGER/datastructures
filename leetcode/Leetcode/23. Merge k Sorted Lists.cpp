    struct CompareHeight {
    bool operator()(ListNode* a, ListNode* b){
          
            return a->val > b->val;
        }
};
    
    ListNode* mergeKLists(vector<ListNode*>& a) {
        
        priority_queue<ListNode*, vector<ListNode*> ,CompareHeight> q;
        
        ListNode* head = NULL;
        ListNode* ans = NULL;
        for(int i=0;i<a.size();i++){
            if(a[i] != NULL)
                q.push(a[i]);
        }
        
        // cout<<q.top()->val<<endl;
        
        while(q.size()){
            ListNode* temp = q.top();
            q.pop();
            if(ans == NULL)
                head = ans = new ListNode();
            else{
                ans->next = new ListNode();
                ans = ans->next;
            }
            if(temp->next != NULL)
                q.push(temp->next);
            ans->val = temp->val;
        }
        
        return head;
        
    }